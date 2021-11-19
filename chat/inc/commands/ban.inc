#!/usr/bin/perl





if($level < 1){



$errors = " Error, command $command not recognized, please use /help for a list of commands.";

        

return $errors;



exit;

}





if($deopped == 1){



$errors = " Error , you are not allowed to use this command.";

 

return $errors;

exit;

       



}





@ban = split(/\s+/, $DATA{'msg'});





if(@ban[1] =~ /\d+\.\d+\.\d+/){



($p1,$p2,$p3)=split(/\./,@ban[1]);



if(length($p1) > 3 or length($p2) > 3 or length($p3) > 3){





$errors = " Syntax: /ban [nick] [reason].";



return $errors;



exit;



           }



}









if(@ban[1] =~ /\d+\.\d+\.\d+/){



$ipban = 1;



}else{



@ban[1] = substr(@ban[1],0,14);



if(@ban[1] eq $DATA{'n'} or @ban[1] eq $realnick){



$errors = " Error, not allowed.";



return $errors;



exit;



} 



unless(@ban[1]){



$errors = " Syntax: /ban [nick] [reason].";



return $errors;



exit;



} 





unless(@ban[2]){



$errors = " Syntax: /ban [nick] [reason].";



return $errors;



exit;



} 

}


$banreason = $DATA{'msg'};



$banreason =~ s/^\/ban//ig;



$banreason =~ s/^\s+//ig;



$banreason =~ s/^@ban[1]//ig;



$banreason =~ s/^\s+//ig;





############################################### IP BAN ###############################################



if($ipban == 1){



if(-e "$root/online/banned/@ban[1].db"){



$errors = " Error, ban <b>@ban[1]</b> already exist.";



return $errors;



exit;



}



dbmopen(%BAN,"$root/online/banned/@ban[1].db",0777);



$BAN{'owner'} = $realnick;



$BAN{'time'} = $fulltime;



$BAN{'bantime'} = $time;



$BAN{'ban'} = "*** Ban <b>@ban[1]</b> by <b>$DATA{'n'} ($realnick)</b> ($ip) for ($banreason). Time: $fulltime.<br>\n";



dbmclose(%BAN);





$msg_action = "<!-- $time -->*** IP BAN: Operator <B>$DATA{'n'} $online_time</b> ($realnick) ($room) banned ip address <B>@ban[1]</b> for ($banreason).<br>\n";



require "$root/inc/msg_action.inc";



undef $msg_action;


open(BANROOM,">>$root/online/rooms/$room.txt");



flock(BANROOM,2);



print BANROOM "<!--servermsg--> *** Ban <b>@ban[1]</b><font size=\"1\" color=\"$iback\">i</font> by Ops <b>$DATA{'n'}</b><font size=\"1\" color=\"$iback\">i</font> for ($banreason).<br>\n";





close(BANROOM);


open(BANLOG,">>$banlogs");

print BANLOG "*** Ban IP @ban[1] by $DATA{'n'} ($realnick) ($ip) for ($banreason). Time: $fulltime.\n";

close(BANLOG);


$errors = " Ban <b>@ban[1]</b> successful.";



return $errors;



exit;





}



########################################################################################################





if(!-e "$root/online/users/@ban[1].db"){



$errors = " Error, user <b>@ban[1]</b> not found.";



return $errors;



exit;



}



#################################### GET USER INFO ######################################################



dbmopen(%BUSER,"$root/online/users/@ban[1].db",0777);



$usr_lev = $BUSER{'level'};



$rrip = $BUSER{'realip'};



if($rrip){



($ip11,$ip22,$ip33)=split(/\./,$rrip);



$rip = "$ip11.$ip22.$ip33";



}

$banip = $BUSER{'ip'};



$broom = $BUSER{'room'};



$rnick = $BUSER{'realnick'};



dbmclose(%BUSER);



######################################################################################################



## CHECK FOR LEVEL



if($level < $usr_lev){



if($usr_lev >= 30){



open(BANANN,">>$root/online/pm/@ban[1].txt");



    print BANANN "<!-- $time --> *** Operator <b>$DATA{'n'}</b> ($realnick) attempted ban ($banreason).<br>\n";



close(BANANN);



}



$errors = " Error , this ban not allowed.";



return $errors;



exit;



}

###################################################



## BAN OP 





open(BANNINGROOM,">>$root/online/rooms/$broom.txt");



flock(BANNINGROOM,2);



print BANNINGROOM "<!--servermsg--> *** Ban <b>@ban[1]</b> by Ops <b>$DATA{'n'}</b> for ($banreason).<br>\n";

close(BANNINGROOM);

if($usr_lev > 0){

dbmopen(%BAN,"$root/online/banned/$rnick.db",0777);

$BAN{'bannedip'} = @ban[1];

$BAN{'ip'} = $realnick;

$BAN{'opsip'} = $ip;

$BAN{'owner'} = $realnick;

$BAN{'time'} = $fulltime;

$BAN{'reason'} = $banreason;

$BAN{'bantime'} = $time;

$BAN{'ban'} = "*** <b>Ops</b> ban <b>$rnick</b> (@ban[1]) by <b>$DATA{'n'} ($realnick)</b> for ($banreason). Time: $fulltime.<br>\n";

dbmclose(%BAN);

dbmopen(%R,"$root/ops/ops/$rnick.db",0777);

$R{'record_bans'}++;

dbmclose(%R);


open(BANLOG,">>$banlogs");

print BANLOG "*** Ops ban $rnick (@ban[1]) by $DATA{'n'} ($realnick) ($room) for ($banreason). Time: $fulltime.\n";

close(BANLOG);





$msg_action = "<!-- $time -->*** OPS BAN: Operator <B>$DATA{'n'}<font size=\"1\" color=\"$iback\">i</font> $online_time</b> ($realnick)<font size=\"1\" color=\"$iback\">i</font> ($room) banned Ops <B>@ban[1]</b><font size=\"1\" color=\"$iback\">i</font> ($rnick) ($broom) for ($banreason).<br>\n";



require "$root/inc/msg_action.inc";



undef $msg_action;



$kill_user = @ban[1];



require "$root/inc/kill_user.inc";



undef $kill_user;







$errors = " Ban <b>@ban[1]</b> successful.";



return $errors;



exit;



}



########



##################################### BAN OUT USER ###########################################



if(-e "$root/online/banned/$banip.db"){



$errors = " Error, ban <b>@ban[1]</b> already exist.";



return $errors;



exit;



}





if($banip != $rip && $rip ne ''){



dbmopen(%BAN,"$root/online/banned/$rip.db",0777);



$BAN{'bannedip'} = $banip;



$BAN{'opsip'} = $ip;



$BAN{'time'} = $fulltime;



$BAN{'owner'} = $realnick;



$BAN{'reason'} = $banreason;



$BAN{'bantime'} = $time;



$BAN{'ban'} = "*** Ban <b>$rip</b> (@ban[1]) by <b>$DATA{'n'} ($realnick)</b> for ($banreason). Time: $fulltime.<br>\n";



dbmclose(%BAN);



}





dbmopen(%BAN,"$root/online/banned/$banip.db",0777);



$BAN{'bannedip'} = $banip;



$BAN{'opsip'} = $ip;



$BAN{'time'} = $fulltime;



$BAN{'owner'} = $realnick;



$BAN{'reason'} = $banreason;



$BAN{'bantime'} = $time;



$BAN{'ban'} = "*** Ban <b>$banip</b> (@ban[1]) by <b>$DATA{'n'} ($realnick)</b> for ($banreason). Time: $fulltime.<br>\n";



dbmclose(%BAN);





$msg_action = "<!-- $time -->*** BAN: Operator <B>$DATA{'n'} $online_time</b> ($realnick) ($room) banned <B>@ban[1]</b> ($rnick) ($broom) for ($banreason).<br>\n";



require "$root/inc/msg_action.inc";

open(BANLOG,">>$banlogs");

print BANLOG "*** BAN: Operator $DATA{'n'} $online_time ($realnick) ($room) banned @ban[1] ($rnick) ($broom) for ($banreason). Time:$fulltime\n";

close(BANLOG);




undef $msg_action;



$kill_user = @ban[1];



require "$root/inc/kill_user.inc";



undef $kill_user;





$errors = " Ban <b>@ban[1]</b> successful.";



return $errors;



exit;
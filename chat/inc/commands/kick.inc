#!/usr/bin/perl





if($command eq '/kick' && $level < 1){





$errors = " Error, command $command not recognized, please use /help for a list of commands.";





return $errors;



exit;        

}









@kick = split(/\s+/, $DATA{'msg'});


@kick[1]=substr(@kick[1],0,14);



$kickreason = $DATA{'msg'};



$kickreason =~ s/^\/kick//ig;



$kickreason =~ s/^\s+//ig;



$kickreason =~ s/^@kick[1]//ig;



$kickreason =~ s/^\s+//ig;



if($deopped == 1){



$errors = " Sorry, you are not allowed to use this command.";

        

return $errors;



exit;

}





unless(@kick[2]){



$errors = " Syntax: /kick [nick] [reason].";

        

return $errors;



exit;



}



if(@kick[1] eq $DATA{'n'}){



$errors = " Syntax: /kick [nick] [reason].";

        

return $errors;



exit;



}







if(!-e "$root/online/users/@kick[1].db") {



$errors = " Error, user <b>@kick[1]</b> not found.";

        

return $errors;



exit;





}



dbmopen(%KICK,"$root/online/users/@kick[1].db",0777);



$kick_level = $KICK{'level'};



$usr_agent = $KICK{'user_agent'};



$fuip = $KICK{'fullip'};



$renick = $KICK{'realnick'};


$left = $time - $KICK{'k_left'};



$usr_agent =~ s/[^\w]//g;



$kick_room = $KICK{'room'};



$fuip =~ s/[^\w]//g;



$kick_it = "$usr_agent$fuip";



dbmclose(%KICK);









if($level < $kick_level){





if($kick_level >= $comm_rank){





open(KICKANN,">>$root/online/pm/@kick[1].txt");



flock(KICKANN,2);



    print KICKANN "<!-- $time --> *** Ops <b>$DATA{'n'}</b><font size=\"1\" color=\"$iback\">i</font> ($realnick) attempted kick ($kickreason).<br>\n";



close(KICKANN);



}



$errors = " Sorry, this kick not allowed.";



return $errors;





exit;

}



if($kick_level >= 1){



dbmopen(%KICKED,"$root/online/kicked/$renick.db",0777);


$KICKED{'kick'} = "*** KICK User <b>@kick[1]</b><font size=\"1\" color=\"$iback\">i</font> ($renick) by <b>$DATA{'n'}</b><font size=\"1\" color=\"$iback\">i</font> ($realnick) for reason ($kickreason).";


$KICKED{'time'} = $time;


dbmclose(%KICKED);

dbmopen(%R,"$root/ops/ops/$renick.db",0777);

$R{'record_kicks'}++;

dbmclose(%R);


dbmopen(%KICKEDD,"$root/online/kicked/$kick_it.db",0777);

$KICKEDD{'kick'} = "*** KICK User <b>@kick[1]</b><font size=\"1\" color=\"$iback\">i</font> ($renick) by <b>$DATA{'n'}</b><font size=\"1\" color=\"$iback\">i</font> ($realnick) for reason ($kickreason).";

$KICKEDD{'time'} = $time;


dbmclose(%KICKEDD);

}else{



dbmopen(%KICKED,"$root/online/kicked/$kick_it.db",0777);



$KICKED{'kick'} = "*** KICK User <b>@kick[1]</b><font size=\"1\" color=\"$iback\">i</font> ($renick) by <b>$DATA{'n'}</b><font size=\"1\" color=\"$iback\">i</font> ($realnick) for reason ($kickreason).";



$KICKED{'time'} = $time;



dbmclose(%KICKED);


}



$kill_user = @kick[1];



require "$root/inc/kill_user.inc";



undef $kill_user;



$msg_action = "<!-- $time -->*** KICK: Operator <B>$DATA{'n'}<font size=\"1\" color=\"$iback\">i</font> $online_time</b> <font size=\"1\" color=\"$iback\">i</font>($realnick) ($room) has kicked <B>@kick[1]</b><font size=\"1\" color=\"$iback\">i</font> ($kick_room) for ($kickreason).<br>\n";



require "$root/inc/msg_action.inc";


open(BANLOG,">>$banlogs");

print BANLOG "*** KICK: Operator $DATA{'n'}<font size=\"1\" color=\"$iback\">i</font> $online_time <font size=\"1\" color=\"$iback\">i</font>($realnick) <font size=\"1\" color=\"$iback\">i</font>($room) has kicked @kick[1] <font size=\"1\" color=\"$iback\">i</font>($kick_room) for ($kickreason).Time: $fulltime.\n";

close(BANLOG);



undef $msg_action;





open(KICKROOM,">>$root/online/rooms/$kick_room.txt");



flock(KICKROOM,2);



print KICKROOM "<!--servermsg--> *** Kick <b>@kick[1]</b> by Ops <b>$DATA{'n'}</b> for ($kickreason).<br>\n";



close(KICKROOM);




$errors = " Kick <b>@kick[1]</b> successful.";



return $errors;



exit;
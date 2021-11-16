#!/usr/bin/perl


if($command eq '/warn' && $level < 1){

$errors = " Error, command $command not recognized, please use /help for a list of commands.";

return $errors;


exit;        

}



@warn = split(/\s+/, $DATA{'msg'});

@warn[1] = substr(@warn[1],0,14);

$reason = $DATA{'msg'};

$reason =~ s/^\/warn//ig;

$reason =~ s/^\s+//ig;

$reason =~ s/^@warn[1]//ig;

$reason =~ s/^\s+//ig;


if($deopped == 1){


$errors = " Sorry, you are not allowed to use this command.";

        return $errors;



exit;

}



unless(@warn[2]){


$errors = " Syntax: /warn [nick] [reason].";

        

return $errors;



exit;



}



if(@warn[1] eq $DATA{'n'}){


$errors = " Syntax: /warn [nick] [reason].";

        

return $errors;



exit;



}



if(!-e "$root/online/users/@warn[1]") {


$errors = " Error, user <b>@warn[1]</b> not found.";

return $errors;

exit;

}



dbmopen(%KICK,"$root/online/users/@warn[1]",0777);


$kick_level = $KICK{'level'};


$kick_room = $KICK{'room'};


dbmclose(%KICK);




if($level < $kick_level){


if($kick_level >= $comm_rank){



open(KICKANN,">>$root/online/pm/@warn[1].txt");


flock(KICKANN,2);


print KICKANN "<!-- $time --> *** Ops <b>$DATA{'n'}</b> <font size=\"1\" color=\"$iback\">i</font>($realnick) attempted kick warning ($reason).<br>\n";



close(KICKANN);



}



$errors = " Sorry, this warning not allowed.";



return $errors;


exit;

}

$msg_action = "<!-- $time -->*** WARNING: Operator <B>$DATA{'n'}<font size=\"1\" color=\"$iback\">i</font> $online_time</b><font size=\"1\" color=\"$iback\">i</font> ($realnick)<font size=\"1\" color=\"$iback\">i</font> ($room) has warned <B>@warn[1]</b> ($kick_room) for ($reason).<br>\n";

require "$root/inc/msg_action.inc";

open(BANLOG,">>$banlogs");

print BANLOG "*** WARNING: Operator $DATA{'n'} <font size=\"1\" color=\"$iback\">i</font>$online_time <font size=\"1\" color=\"$iback\">i</font>($realnick) <font size=\"1\" color=\"$iback\">i</font>($room) has warned @warn[1] ($kick_room) for ($reason).Time: $fulltime.\n";

close(BANLOG);

undef $msg_action;

open(KICKROOM,">>$root/online/rooms/$kick_room.txt");

flock(KICKROOM,2);





print KICKROOM "<!--servermsg--> *** KICK WARNING User <b>@warn[1]</b> warned by <b>$DATA{'n'}</b> for ($reason).<br>\n";

close(KICKROOM);


open(A,">>$root/online/pm/@warn[1].txt");


flock(A,2);


print A "<!-- $time --> <b>*** OPS <b>$DATA{'n'}</b> IS WARNING YOU for reason ($reason).</b> $title is friendly chat, please respect our rules.<br>\n";



close(A);


$errors = " Kick warning sent to user <b>@warn[1]</b>.";

return $errors;

exit;


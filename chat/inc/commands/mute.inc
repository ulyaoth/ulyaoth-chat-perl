#!/usr/bin/perl


if($level < 1){
                
$errors = " Error, command $command not recognized, please use /help for a list of commands.";

return $errors;

exit;

}


@mute = split(/\s+/, $DATA{'msg'});


unless(@mute[1]){


$errors = "Syntax: /mute [nick] , /mute - [nick]";

return $errors;

exit;

}




if(@mute[1] eq '-'){


if(!-e "$root/online/users/@mute[2].db"){

$errors = " Error, user <b>@mute[2]</b> not found.";

return $errors;

exit;

}


dbmopen(%USER,"$root/online/users/@mute[2].db",0777);

if($USER{'level'} >= 1 && $level < $comm_rank){

dbmclose(%USER);

$errors = " Error, mute of Ops is not allowed.";

return $errors;

exit;


}

undef $USER{'muted'};

$msg_action = "<!-- $time -->*** MUTE: Mute user <B>@mute[2]</b> ($USER{'room'}) removed by <b>$DATA{'n'}</b> ($room).<br>\n";

require "$root/inc/msg_action.inc";

undef $msg_action;


$errors = " Mute removed.";

return $errors;

exit;


dbmclose(%USER);


}


if(!-e "$root/online/users/@mute[1].db"){

$errors = " Error, user <b>@mute[2]</b> not found.";

return $errors;

exit;

}


dbmopen(%USER,"$root/online/users/@mute[1].db",0777);

if($USER{'level'} >= 1 && $level < $comm_rank){

dbmclose(%USER);

$errors = " Error, mute of Ops is not allowed.";

return $errors;

exit;


}

$USER{'muted'} = 1;

$errors = " User <b>@mute[1]</b> muted.";

$msg_action = "<!-- $time -->*** MUTE: Mute user <B>@mute[1]</b> ($USER{'room'}) applied by <b>$DATA{'n'}</b> ($room).<br>\n";

require "$root/inc/msg_action.inc";

undef $msg_action;

dbmclose(%USER);

return $errors;

exit;
#!/usr/bin/perl

if($level < $staff_rank){
                
$errors = " Error, command $command not recognized, please use /help for a list of commands.";

return $errors;

exit;

}


@sban = split(/\s+/, $DATA{'msg'});

unless(@sban[2]){

$errors = "Syntax: /sban [nick] [reason].";

return $errors;

exit;

}


if(!-e "$root/online/users/@sban[1].db"){

$errors = " Error, user <b>@sban[1]</b> not found.";

return $errors;

exit;

}


dbmopen(%USER,"$root/online/users/@sban[1].db",0777);

if($USER{'level'} >= 1){

dbmclose(%USER);

$errors = " Error, sban on Ops is not allowed.";

return $errors;

exit;


}

$USER{'sbanned'} = "yes";

$msg_action = "<!-- $time -->*** SBAN: User <B>@sban[1]</b> ($USER{'room'}) s-banned by Ops <b>$DATA{'n'}</b> ($room).<br>\n";

require "$root/inc/msg_action.inc";

undef $msg_action;

$errors = " S-ban successful.";

return $errors;

dbmclose(%USER);

exit;
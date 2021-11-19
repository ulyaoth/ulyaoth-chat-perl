#!/usr/bin/perl

@intro = split(/\s+/, $DATA{'msg'});

$in = $DATA{'msg'};

$in =~ s/^\/intro//;

$in =~ s/^\s+//;

dbmopen(%USER,"$root/online/users/$DATA{'n'}.db",0777);

$d = $USER{'intro_msg'};

dbmclose(%USER);


if(!@intro[1] or !$d && !@intro[2]){

if(!$d){

$d = "unset";
}

$errors = " Syntax: /intro [nick] to send, /intro [message] to set, /intro - to disable. Current intro message ($d).";

return $errors;

exit;

}


if(@intro[2]){

dbmopen(%USER,"$root/online/users/$DATA{'n'}.db",0777);

$USER{'intro_msg'} = $in;

dbmclose(%USER);

$errors = " Intro message has been saved ($in). Use: /intro [nick] to send this message to someone.";

return $errors;

exit;

}


if(@intro[1] eq '-'){

dbmopen(%USER,"$root/online/users/$DATA{'n'}.db",0777);

undef $USER{'intro_msg'};

dbmclose(%USER);

$errors = " Intro system has been disabled. Syntax: /intro [nick] to send intro, /intro [message] to set, /intro - to disable.";

return $errors;

exit;

}


if(!-e "$root/online/users/@intro[1].db"){

$errors = " Error, user <b>@intro[1]</b> not found. Intro action aborted.";

return $errors;

exit;

}


dbmopen(%USER,"$root/online/users/$DATA{'n'}.db",0777);

$int = $USER{'intro_msg'};

dbmclose(%USER);

open(PR,">>$root/online/pm/@intro[1].txt");

flock(PR,2);

print PR "<!-- $time --> <A HREF=\"javascript:m('$DATA{'n'}')\"><B>\*$DATA{'n'}\*</b></a><font size=\"1\" color=\"$iback\">i</font> ($ip) $int<br>\n";

close(PR);


$errors = " Intro has been sent. --> <b>\*@intro[1]\*</b><font size=\"1\" color=\"$iback\">i</font> $int";

return $errors;

exit;
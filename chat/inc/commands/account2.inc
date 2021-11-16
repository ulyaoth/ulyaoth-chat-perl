#!/usr/bin/perl


if ($command eq '/account2' && $level < 1){

$errors = " Error, command $command not recognized, please use /help for a list of commands.";

return $errors;

exit;

}


if(!$DATA{'chpass'}){

$errors = " Thank you.";

return $errors;

exit;

}


if(!$DATA{'password1'} or !$DATA{'password2'} or !$DATA{'passw'}){

$errors = " Error, you left one or more fields blank, please click <a href=\"$location?n=$DATA{'n'}&id=$DATA{'id'}&room=$room&msg=/account\"><b>here</b></a> to go back and correct error.";

return $errors;

exit;

}

if($DATA{'password1'} ne $DATA{'password2'}){

$errors = " Error, passwords do not match, please click <a href=\"$location?n=$DATA{'n'}&id=$DATA{'id'}&room=$room&msg=/account\"><b>here</b></a> to go back and correct error.";

return $errors;

exit;

}


dbmopen(%PASS,"$root/ops/ops/$realnick",0777);

$s = crypt($DATA{'passw'}, "Cd");

if($s ne $PASS{'password'}){

$errors = " Invalid password, for security reasons you will be disconnected now."; 

dbmclose(%PASS);

$kill_user = $DATA{'n'};

require "$root/inc/kill_user.inc";

undef $kill_user;

return $errors;

exit;

}

$PASS{'password'} = crypt($DATA{'password2'}, "Cd");

$PASS{'realpassword'} = $DATA{'password1'};

dbmclose(%PASS);


$errors = " New password accepted. We suggest you relogin now. If you have any problems with it please contact us as soon as possible.";

return $errors;

exit;



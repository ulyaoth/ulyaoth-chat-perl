#!/usr/bin/perl


@wid = split(/\s+/, $DATA{'msg'});


if(@wid eq "" or @wid[1] < 30 or @wid[1] > 150){

$errors = " Error, you must specify a width of message box between 30 and 150.";

return $errors;

exit;

}



dbmopen(%USER,"$root/online/users/$DATA{'n'}.db",0777);

$USER{'wid'} = @wid[1];

dbmclose(%USER);

$bypass = 1;

$wid = @wid[1];

return $wid;

return $bypass;

exit;
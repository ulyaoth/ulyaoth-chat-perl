#!/usr/bin/perl



@speed = split(/\s+/, $DATA{'msg'});


if(@speed eq "" or @speed[1] < 10 or @speed[1] > 800){


$errors = " Syntax: /speed [10-800]. Error, you must specify a speed between 10 and 800.";


return $errors;

exit;

}


dbmopen(%USER,"$root/online/users/$DATA{'n'}.db",0777);

$USER{'speed'} = @speed[1];

dbmclose(%USER);

$bypass = 1;

$len = @len[1];

$errors = " Speed set to <b>@speed[1]</b> seconds.";

return $speed;

return $errors;

exit;
























#!/usr/bin/perl


@ips = split(/\s+/, $DATA{'msg'});


if(@ips[1] == 1){

dbmopen(%IP,"$root/online/users/$DATA{'n'}",0777);

$IP{'ips_control'} = "one";

dbmclose(%IP);

$errors = " Ip switching security set to level 1. Security (low\/default).";

return $errors;

exit;

}


if(@ips[1] == 2){

dbmopen(%IP,"$root/online/users/$DATA{'n'}",0777);

$IP{'ips_control'} = "two";

dbmclose(%IP);

$errors = " Ip switching security set to level 2. Security (medium).";

return $errors;

exit;

}

if(@ips[1] == 3){

dbmopen(%IP,"$root/online/users/$DATA{'n'}",0777);

$IP{'ips_control'} = "three";

dbmclose(%IP);

$errors = " Ip switching security set to level 3. Security (high).";

return $errors;

exit;

}

if(@ips[1] == 4){

dbmopen(%IP,"$root/online/users/$DATA{'n'}",0777);

$IP{'ips_control'} = "four";

dbmclose(%IP);

$errors = " Ip switching security set to level 4. Security (maximum security, ip switching is not allowed).";

return $errors;

exit;

}




if(@ips[1] == 0){

dbmopen(%IP,"$root/online/users/$DATA{'n'}",0777);

$IP{'ips_control'} = 0;

dbmclose(%IP);

$errors = " Ip switching security set to level 0. Security (none, ip switching allowed).";

return $errors;

exit;

}


$errors = " Syntax: /ips [1-4].";

return $errors;

exit;



        
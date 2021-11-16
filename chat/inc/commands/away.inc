#!/usr/bin/perl


dbmopen(%USER,"$root/online/users/$DATA{'n'}",0777);

if($USER{'mode'}){

undef $USER{'mode'};

dbmclose(%USER);

$errors = "Away mode <b>OFF</b>, welcome back!!!";

return $errors;

exit;

}else{

$USER{'mode'} = "<b>:AWAY</b>";

$errors = "Away mode <b>ON</b>.";

dbmclose(%USER);

return $errors;

exit;

}




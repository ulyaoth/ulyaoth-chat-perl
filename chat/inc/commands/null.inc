#!/usr/bin/perl


dbmopen(%USER,"$root/online/users/$DATA{'n'}.db",0777);

if($USER{'null'}){

undef $USER{'null'};

dbmclose(%USER);

$errors = " Null mode <b>OFF</b>. Summoning enabled.";

return $errors;

exit;

}else{
     
$USER{'null'} = 1;

dbmclose(%USER);

$errors = " Null mode <b>ON</b>. Operators can no longer summon you. Use /null to disable.";

return $errors;

exit;

} 
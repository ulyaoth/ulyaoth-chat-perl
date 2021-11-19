#!/usr/bin/perl


@len = split(/\s+/, $DATA{'msg'});


if(@len eq "" or @len[1] < 5 or @len[1] > 40){



$errors = " Syntax: /len [5-40]. Error, you must specify a length between 5 and 40 lines.";



return $errors;

exit;

}



dbmopen(%USER,"$root/online/users/$DATA{'n'}.db",0777);

$USER{'len'} = @len[1];

dbmclose(%USER);

$bypass = 1;

$len = @len[1];


$errors = " Main screen length set to <b>@len[1]</b> lines.";


return $len;

return $errors;

exit;
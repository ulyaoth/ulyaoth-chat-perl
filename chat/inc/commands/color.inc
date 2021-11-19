#!/usr/bin/perl



@crayon = split(/\s+/, $DATA{'msg'});

@crayon[1] =~ s/[^\w]//g;

if(@crayon[1] eq ""){

dbmopen(%USER,"$root/online/users/$DATA{'n'}.db",0777);

if(!$USER{'font'}){

$USER{'ecolor'} = "";

$USER{'color'} = "";

}else{

$USER{'color'} = "<font face=\"$USER{'font'}\">";

}

undef $USER{'xcolor'};

dbmclose(%USER);


$errors = " Font color unset.";

return $errors;

}else{


@crayon[1]=substr(@crayon[1],0,15);

dbmopen(%USER,"$root/online/users/$DATA{'n'}.db",0777);

$USER{'ecolor'} = "</font>";

if($USER{'font'}){

$ex = "face=\"$USER{'font'}\"";

}

$USER{'color'} = "<font color=\"@crayon[1]\" $ex>";

$USER{'xcolor'} = @crayon[1];


dbmclose(%USER);


$errors = " Font color set to <font color=\"@crayon[1]\">@crayon[1]</font>.";

return $errors;

}
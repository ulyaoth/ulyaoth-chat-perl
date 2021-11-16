#!/usr/bin/perl


@crayon = split(/\s+/, $DATA{'msg'});

@crayon[1] =~ s/[^\w]//g;

if(@crayon[1] eq ""){

dbmopen(%USER,"$root/online/users/$DATA{'n'}",0777);

$USER{'nickcolor'} = "";

dbmclose(%USER);

$errors = " Nickname font color unset.";

return $errors;

}else{


@crayon[1]=substr(@crayon[1],0,15);

dbmopen(%USER,"$root/online/users/$DATA{'n'}",0777);

$USER{'nickcolor'} = @crayon[1];

dbmclose(%USER);


$errors = " Nickname font color set to <font color=\"@crayon[1]\">@crayon[1]</font>.";

return $errors;

}



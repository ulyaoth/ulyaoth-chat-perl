#!/usr/bin/perl


@crayon = split(/\s+/, $DATA{'msg'});

@crayon[1] =~ s/[^\w]//g;

if(@crayon[1] eq ""){

dbmopen(%USER,"$root/online/users/$DATA{'n'}.db",0777);

$USER{'bgcolor'} = "";

$USER{'text'} = "";

dbmclose(%USER);

$errors = " Text color unset.";

$bgcolor= "";

$text = "";

return $errors;

return $bgcolor;

return $text;


}else{


@crayon[1]=substr(@crayon[1],0,15);

dbmopen(%USER,"$root/online/users/$DATA{'n'}.db",0777);

$USER{'text'} = "text=\"@crayon[1]\"";

dbmclose(%USER);

$errors = " Text color set to <font color=\"@crayon[1]\">@crayon[1]</font>.";

$text = "text=\"@crayon[1]\"";

return $text;

return $errors;

}
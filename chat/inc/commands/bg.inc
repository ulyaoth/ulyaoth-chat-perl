#!/usr/bin/perl


@crayon = split(/\s+/, $DATA{'msg'});

@crayon[1] =~ s/[^\w]//g;


if(@crayon[1] eq ''){


dbmopen(%USER,"$root/online/users/$DATA{'n'}",0777);

$USER{'bgcolor'} = "";

$USER{'realbgcolor'} = "";

$USER{'text'} = "";

dbmclose(%USER);

$bgcolor= "";

$text = "";

$errors = " Background color unset.";

}else{


@crayon[1]=substr(@crayon[1],0,15);

dbmopen(%USER,"$root/online/users/$DATA{'n'}",0777);

$USER{'realbgcolor'} = @crayon[1];

$USER{'bgcolor'} = "bgcolor=\"@crayon[1]\"";

dbmclose(%USER);

$errors = " Background color set to @crayon[1].";

$bgcolor = "bgcolor=\"@crayon[1]\"";

return $bgcolor;

return $errors;
return true;
exit;

}


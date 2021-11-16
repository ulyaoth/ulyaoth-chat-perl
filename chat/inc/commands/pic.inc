#!/usr/bin/perl

if($level >= 1){

@pic = split(/\s+/, $DATA{'msg'});



if(@pic[1] eq ""){

dbmopen(%USER,"$root/online/users/$DATA{'n'}",0777);

undef $USER{'nickname'};

dbmclose(%USER);

$errors = " Picture link unset.";

return $errors;

exit;

}else{

@pic[1]=substr(@pic[1],0,100);

@pic[1] =~ s/<//ig;

@pic[1] =~ s/>//ig;


if(@pic[1]!~/http:\/\//){
   
@pic[1] = "http://@pic[1]";


  }

dbmopen(%USER,"$root/online/users/$DATA{'n'}",0777);

$USER{'nickname'} = "<a href=\"@pic[1]\" target=\"_blank\">";

dbmclose(%USER);

$errors = " Picture link set to <a href=\"@pic[1]\" target=_blank>@pic[1]</a>.";

return $errors;

exit;
}

}else{

$errors = " Error, command $command not recognized, please use /help for a list of commands.";
        
return $errors;

exit;


}























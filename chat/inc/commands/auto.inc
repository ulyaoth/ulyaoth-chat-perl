#!/usr/bin/perl



if ($level < 1 && $level){

                

        $errors = " Error, command $command not recognized, please use /help for a list of commands.";

return $errors;

exit;



       }


foreach $pmimg(@imegs){

$DATA{'msg'} =~ s/$pmimg\b/<img src=\"\/img$pmimg.gif\">/g;

}





$text = $DATA{'msg'};



$text =~ s/^\/auto//;

$text =~ s/^\s+//;


@auto = split(/\s+/, $DATA{'msg'});



foreach $key(@auto){

if($key =~ /<img/){

$z++;
}
}


if($z > 5){

$errors = " Error, you can not post more than 5 images per message.";

return $errors;

exit;


}


if(!@auto[1]){


dbmopen(%USER,"$root/online/users/$DATA{'n'}.db",0777);

$f = $USER{'auto_replay'};

dbmclose(%USER);

if(!$f){

$f = "unset";
		}

$errors = " Syntax: /auto [message]. Current auto replay message ($f).";

return $errors;

exit;   

}


dbmopen(%PREF,"$root/opspreferences/$realnick.db",0777);

$PREF{'auto_replay'} = $text;

dbmclose(%PREF);

dbmopen(%USER,"$root/online/users/$DATA{'n'}.db",0777);

$USER{'auto_replay'} = $text;

dbmclose(%USER);



$errors = " Auto replay message successfuly added ($text).";


return $errors;



exit;    
#!/usr/bin/perl



if($command eq '/img' && $level < 1){



$errors = " Error, command $command not recognized, please use /help for a list of commands.";
        
return $errors;

exit;


}


@link = split(/\s+/,$DATA{'msg'});



unless(@link[2]){

$errors = " Syntax: /img [nick] [url].";

return $errors;

exit;

}

if(length(@link[1]) > 14){

$errors = " Syntax: /img [nick] [url].";

return $errors;

exit;


}


if(!-e "$root/online/users/@link[1]"){

$errors = " Error, user <b>@link[1]</b> not found.";

return $errors;

exit;

}


if(@link[2]!~/\./ or @link[2] =~ /\"/ or @link[2] =~ /\'/ or @link[2] =~ /\[/){

$errors = " Syntax: /img [nick] [url].";

return $errors;

exit;

}


if(@link[2]!~/^http:\/\//){
   
@link[2] = "http://@link[2]";


  }


open(LINKPM,">>$root/online/pm/@link[1].txt");

print LINKPM "<!-- $time --> *** <b>[$DATA{'n'}]</b><font size=\"1\" color=\"$iback\">i</font> <a href=\"@link[2]\" target=_blank>@link[2]</a><br>\n";

close(LINKPM);

$errors = " Link Sent -> <b>@link[1]</b> <a href=\"@link[2]\" target=_blank>@link[2]</a>";

return $errors;

exit;


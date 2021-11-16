#!/usr/bin/perl

if($level < 1){

$errors = " Error, command $command not recognized, please use /help for a list of commands.";
        
return $errors;

exit;


}


@link = split(/\s+/,$DATA{'msg'});

$linky = $DATA{'msg'};

$linky =~ s/^\/link//ig;

$linky =~ s/^\s+//ig;

$linky =~ s/^@link[1]//ig;

$linky =~ s/^\s+//ig;




unless(@link[2]){

$errors = " Syntax: /link [url] [message].";

return $errors;

exit;

}


if(@link[1] =~ /\'/ or @link[1] =~ /\"/ or @link[1] =~ /\[/){

$errors = " Syntax: /link [url] [message].";
        
return $errors;

exit;



}




if(@link[1]!~/^http:\/\//){
   
@link[1] = "http://@link[1]";


  }



open(LINKROOM,">>$root/online/rooms/$room.txt");

flock(LINKROOM,2);

print LINKROOM "<font color=\"\#000000\">\[</font><A style=\"text-decoration: none\; color: $nickcolor\; font-family: $nicktype\" href=\"javascript:m('$DATA{'n'}')\"><b>$DATA{'n'}</b></a><font color=\"\#000000\">\]</font><font size=\"1\" color=\"$iback\">i</font> <a href=\"@link[1]\" target=_blank>$linky</a><br>\n";


close(LINKROOM);

$bypass = 1;



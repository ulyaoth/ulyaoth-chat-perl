#!/usr/bin/perl


if ($level < 1 && $level ne "granted"){
                
        $errors = " Error, command $command not recognized, please use /help for a list of commands.";

return $errors;


exit;

       }



foreach $pmimg(@imegs){

$DATA{'msg'} =~ s/$pmimg\b/<img src=\"\/img$pmimg.gif\">/g;

}


$red = $DATA{'msg'};

$red =~ s/^\/\/su//;

@ared = split(/\s+/, $DATA{'msg'});


foreach $key(@ared){

if($key =~ /<img/){

$z++;
}
}


if($z > 5){

$errors = " Error, you can not post more than 5 images per message.";

return $errors;

exit;


}



if(!@ared[1]){

$errors = " Syntax: //su [message].";

return $errors;

exit;   

}

@red_message = split(/\s+/,$red);

foreach $key(@red_message){

if($key =~ /^\/\//){

$a_key = $key;

$a_key =~ s/^\/\///ig;

$one_key = substr($a_key,0,6);

if(length($key) > 8 && $one_key !~ /[\W]/){

$a_key = substr($a_key,6,length($a_key));

$key = "<font color=\"$one_key\">$a_key</font>";

}

}
}


open(RED,">>$root/online/rooms/$room.txt");

flock(RED,2);



print RED "<font color=\"\#000000\">\[</font><A style=\"text-decoration: none\; color: $nickcolor\; font-family: $nicktype\" href=\"javascript:m('$DATA{'n'}')\"><b>$DATA{'n'}</b></a><font color=\"\#000000\">\]</font><font size=\"1\" color=\"$iback\">i</font>$scolor <sub>@red_message</sub>$ecolor<br>\n";


close(RED);


$bypass = 1;

return $bypass;

exit;
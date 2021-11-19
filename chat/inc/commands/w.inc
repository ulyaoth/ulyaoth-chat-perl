#!/usr/bin/perl


if ($level < 1 && $level ne "granted"){
                
        $errors = " Error, command $command not recognized, please use /help for a list of commands.";

return $errors;

exit;

       }


foreach $pmimg(@imegs){

$DATA{'msg'} =~ s/$pmimg\b/<img src=\"\/img$pmimg.gif\">/g;

}


$green = $DATA{'msg'};

$green =~ s/^\/\/w//;

@ablue = split(/\s+/, $DATA{'msg'});

foreach $key(@ablue){

if($key =~ /<img/){

$z++;
}
}


if($z > 5){

$errors = " Error, you can not post more than 5 images per message.";

return $errors;

exit;


}




if(!@ablue[1]){

$errors = " Syntax: //w [message].";

return $errors;

exit;   

}

@green_message = split(/\s+/,$green);

foreach $key(@green_message){

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



print RED "<font color=\"\#000000\">\[</font><A style=\"text-decoration: none\; color: $nickcolor\; font-family: $nicktype\" href=\"javascript:m('$DATA{'n'}')\"><b>$DATA{'n'}</b></a><font color=\"\#000000\">\]</font><font size=\"1\" color=\"$iback\">i</font> <font color=\"#FFFFFF\"><b> @green_message</b></font><br>\n";


close(RED);


$bypass = 1;

return $bypass;

exit;
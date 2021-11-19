#!/usr/bin/perl


if($level < 1){
                
        $errors = " Error, command $command not recognized, please use /help for a list of commands.";

return $errors;

exit;

       }


foreach $pmimg(@imegs){

$DATA{'msg'} =~ s/$pmimg\b/<img src=\"\/img$pmimg.gif\">/g;

}



$text_action = $DATA{'msg'};

$text_action =~ s/^\/box//ig;

$text_action =~ s/^\s+//ig;

@action = split(/\s+/, $DATA{'msg'});

if(@action[1] =~ /[\W]/){

$errors = " Syntax: /box [color] [text].";

return $errors;

exit;



}



$text_action =~ s/^@action[1]//;

$text_action =~ s/^\s+//;

foreach $key(@action){

if($key =~ /<img/){

$z++;
}
}


if($z > 5){

$errors = " Error, you can not post more than 5 images per message.";

return $errors;

exit;


}


if(!@action[2]){

$errors = " Syntax: /box [color] [text].";

return $errors;

exit;


}


@mes = split(/\s+/,$text_action);

foreach $key(@mes){

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


open(ACT,">>$root/online/rooms/$room.txt");

flock(ACT,2);

print ACT "<!--$realnick--> <font color=\"\#000000\">\[</font><A style=\"text-decoration: none\; color: $nickcolor\; font-family: $nicktype\" href=\"javascript:m('$DATA{'n'}')\"><b>$DATA{'n'}</b></a><font color=\"\#000000\">\]</font><font size=\"1\" color=\"$iback\">i</font> <span style=\"background-color: @action[1]\">@mes </span>$ecolor<br>\n";

close(ACT);


$bypass = 1;

return $bypass;

exit;
#!/usr/bin/perl





if ($command eq '/rose' && $level < 1){

                

        $errors = " Error, command $command not recognized, please use /help for a list of commands.";



return $errors;





exit;



       }


foreach $pmimg(@imegs){

$DATA{'msg'} =~ s/$pmimg\b/<img src=\"\/img$pmimg.gif\">/g;

}


$z = 0;

@d = split(/\s+/,$DATA{'msg'});


foreach $key(@d){

if($key =~ /<img/){

$z++;
}
}


if($z > 5){

$errors = " Error, you can not post more than 5 images per message.";

return $errors;

exit;


}



$rose = $DATA{'msg'};



$rose =~ s/^\/rose//ig;



$rose =~ s/^\s+//ig;



@arose = split(/\s+/, $DATA{'msg'});



@arose[1] =~ s/[^\w]//g;



@arose[1] = substr(@arose[1],0,6);









$rose =~ s/^@arose[1]//g;







if(!@arose[2]){



$errors = " Syntax: /rose [hex color] [message].";



return $errors;



exit;   



}



###########







@rose_message = split(/\s+/,$rose);



foreach $key(@rose_message){



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

#######################



open(RED,">>$root/online/rooms/$room.txt");



flock(RED,2);



print RED "<b>* $DATA{'n'}<font size=\"1\" color=\"$iback\">i</font> <font color=\"#003399\">~~{~~{</font><font color=\"@arose[1]\">@</font><font color=\"#003399\">~~{~~{</font><font color=\"@arose[1]\">@</font><font color=\"#003399\">~~{~~{</font><font color=\"@arose[1]\">@</font></b> @rose_message <b><font color=\"@arose[1]\">@</font><font color=\"#003399\">}~~}~~</font><font color=\"@arose[1]\">@</font><font color=\"#003399\">}~~}~~</font><font color=\"@arose[1]\">@</font><font color=\"#003399\">}~~}~~</font></b><br>\n";





close(RED);





$bypass = 1;



return $bypass;



exit;











        
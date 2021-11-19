#!/usr/bin/perl


if ($command eq '/rose5' && $level < 1){

                

        $errors = " Error,  $command not recognized, please use /help for a list of commands.";





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




$reed = $DATA{'msg'};



$reed =~ s/^\/rose5//;



@red = split(/\s+/, $DATA{'msg'});



if(@red[1] eq ''){



$errors = " Syntax: /rose5 [message].";



return $errors;



exit;   



}









########







@rose_message = split(/\s+/,$reed);



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



########################


open(RED,">>$root/online/rooms/$room.txt");



flock(RED,2);



print RED "<!--$realnick--> <b>* $DATA{'n'}<font size=\"1\" color=\"$iback\">i</font> <font color=#ffdead>{</font><font color=#ff1493>{</font><font color=#ffd500>{</font><font color=#ff4500>(</font><font color=#cc0022>(</font><font color=#ff8800>(</font><font color=#8899FF>*</font><font color=#ff0000>*</font><font color=#ffdead>*</font></b> @rose_message <b><font color=#ff1493>*</font><font color=#ffd500>*</font><font color=#ff4500>*</font><font color=#cc0022>)</font><font color=#ff8800>)</font><font color=#ff8800>)</font><font color=#ffd500>}</font><font color=#8899FF>}</font><font color=#ff0000>}</font></b><br>\n";



close(RED);



$bypass = 1;



return $bypass;



exit;
#!/usr/bin/perl

use CGI;
use Fcntl;
use DB_File;

$root = '/opt/ulyaoth/chat';


&data();

require "$root/inc/variables.inc";


#if ($DATA{'n'} =~ /[^\w|Α|Θ|Κ|Λ|Μ|Ν|Ξ|Ο|δ|Ρ|Σ|Τ|Υ|Φ|Ψ|Ω|Ϊ|Ϋ|έ|ή|ί|α|γ|δ|ζ|ν|ΐ|Β|Γ|Δ|Ε|Ζ|Η|Ι|Π|Φ|Ò|ΰ|ε|ζ|η|θ|ι|κ|λ|μ|ν|ξ|ο]/i) {

#} else {

#print "Content-type: text/html\n\n";

#$loginerror = "";

#require "$root/inc/login.inc";

#exit;

#}

#############

@arab = ("Α","Θ","Κ","Λ","Μ","Ν","Ξ","Ο","δ","Ρ","Σ","Τ","Υ","Φ","Ψ","Ω","Ϊ","Ϋ","ά","έ","ή","ί","α","γ","δ","ζ","ν","ΐ","Β","Γ","Δ","Ε","Ζ","Η","Ι","Π","Φ","Ò","ΰ","ε","ζ","η","θ","ι","κ","λ","μ","ν","ξ","ο");

#Η Θ Κ Λ Μ Ν Ξ Ο Π Ρ Ò Σ Τ Υ Φ Ψ Ω Ϊ Ϋ έ ή ί α γ δ εά ζ ν

$nn = $DATA{'n'};

foreach $q (@arab) {

if ($nn =~ /$q/i) {

$nn =~ s/$q//i;

$arabic = 1;

   }
}


if ($DATA{'n'} =~ /[^a-zA-Z0-9_\Α\Θ\Κ\Λ\Μ\Ν\Ξ\Ο\δ\Ρ\Σ\Τ\Υ\Φ\Ψ\ψ\Ω\Ϊ\Ϋ\ά\έ\ή\ί\α\γ\δ\ζ\ν\ΐ\Β\Γ\Δ\Ε\Ζ\Η\Π\Φ\Ò\ΰ\ε\ζ\η\θ\ι\κ\λ\μ\ν\ξ\ο]/i) {

print "Content-type: text/html\n\n";

$loginerror = "";

require "$root/inc/login.inc";

exit;

}

#############




if(!$DATA{'n'} or length($DATA{'n'}) > 15 or $DATA{'n'} =~ /\./ or $DATA{'n'} =~ /db/i){

print "Content-type: text/html\n\n";

$loginerror = "";

require "$root/inc/login.inc";

exit;

}

#$DATA{'n'} =~ s/[^\w]//ig;


if (!$DATA{'n'} or length($DATA{'n'}) > 15 or !-e "$root/online/users/$DATA{'n'}.db"){

do "$root/cgi/login.cgi";

exit;

} 


dbmopen(%USER,"$root/online/users/$DATA{'n'}.db",0777);

$id = $USER{'id'};

$realnick = $USER{'realnick'};

$room = $USER{'room'};

$nickname = $USER{'nickname'};

$online_time = $time - $USER{'online'};

$ip = $USER{'ip'};

$speed = $USER{'speed'};

if($USER{'user_agent'} ne $ENV{'HTTP_USER_AGENT'}){

$loginerror = " *** Id session switching is not allowed once you are logged in. Please relogin again.";

print "Content-type: text/html\n\n";

require "$root/inc/login.inc";

exit;

}
$menu = $USER{'menu'};

$level = $USER{'level'};

$opsid = $USER{'opsid'};

$nickcolor = $USER{'nickcolor'};

$mode = $USER{'mode'};

$deopped = $USER{'deopped'};

$frames = $USER{'frames'};

$nicktype = $USER{'nfont'};

$ecolor = $USER{'ecolor'};

$scolor = $USER{'color'};

$wid = $USER{'wid'};

$summoner = $USER{'summoner'};

$summonroom = $USER{'summonroom'};

## ips

($ips1,$ips2,$ips3,$ips4) = split(/\./,$ENV{'REMOTE_ADDR'});

($oips1,$oips2,$oips3,$oips4) = split(/\./,$USER{'fullip'});


if($USER{'ips_control'} eq "one"){

if($ips1 ne $oips1){

dbmclose(%USER);

$loginerror = " *** IP switching is NOT allowed ($oips1. -> $ENV{'REMOTE_ADDR'})";

print "Content-type: text/html\n\n";

require "$root/inc/login.inc";

exit;

		}

}



if($USER{'ips_control'} eq "two"){

if($ips1 ne $oips1 or $ips2 ne $oips2){

dbmclose(%USER);

$loginerror = " *** IP switching is NOT allowed ($oips1.$oips2 -> $ENV{'REMOTE_ADDR'})";

print "Content-type: text/html\n\n";

require "$root/inc/login.inc";

exit;

		}	

}



if($USER{'ips_control'} eq "three"){

if($ips1 ne $oips1 or $ips2 ne $oips2 or $ips3 ne $oips3){

dbmclose(%USER);

$loginerror = " *** IP switching is NOT allowed ($oips1.$oips2.$oips3 -> $ENV{'REMOTE_ADDR'})";

print "Content-type: text/html\n\n";

require "$root/inc/login.inc";

exit;

		}


}


if($USER{'ips_control'} eq "four"){

if($ips1 ne $oips1 or $ips2 ne $oips2 or $ips3 ne $oips3 or $ips4 ne $oips4){

dbmclose(%USER);

$loginerror = " *** IP switching is NOT allowed ($oips1.$oips2.$oips3.$oips4 -> $ENV{'REMOTE_ADDR'})";

print "Content-type: text/html\n\n";

require "$root/inc/login.inc";

exit;

		}

}


###############################################################

$bgcolor = $USER{'bgcolor'};

if(!$USER{'realbgcolor'}){

$iback = "\#FFFFFF";

}else{

$iback = $USER{'realbgcolor'};

}

$text = $USER{'text'};

$len = $USER{'len'};

$USER{'idle'} = $time;

$fr = $USER{'fr'};

if($DATA{'msg'} eq $USER{'lastmsg'}){

$bypass = 1;

}


$muted = $USER{'muted'};

#########

#$flood = $time - $USER{'msg_flood'};

#if($USER{'flooder_time'} < $time){

#if($flood < 2 && length($DATA{'msg'}) >= 100){

#$no_flood = 15;

#}elsif($flood < 2 && length($DATA{'msg'}) < 100){

#$no_flood = 6;

#}elsif($flood > 2 && $flood < 6){

#$no_flood = 4;

#}

#$USER{'flooder_time'} = $time + $no_flood;

#}


#$no_flood = $USER{'flooder_time'} - $time;


#if($no_flood && $DATA{'msg'} ne "" && $DATA{'msg'} !~ /^\// && $DATA{'msg'} !~ /^\m/){

#$errors = " Error, posting too fast, please wait <b>$no_flood</b> seconds and try reposting your message.";

#}

#if($DATA{'msg'} ne "" && $DATA{'msg'} !~ /^\// && $DATA{'msg'} !~ /^\m/){

#$USER{'msg_flood'} = $time;

#}

############

if($DATA{'msg'} ne "" && $DATA{'msg'} !~ /^\// && $DATA{'msg'} !~ /^\m/){

$USER{'lastmsg'} = $DATA{'msg'};

}


if($id ne $DATA{'id'} or $DATA{'id'} eq ""){

dbmclose(%USER);

do "$root/cgi/login.cgi";

exit;

}

if($USER{'level'} < 1 && $USER{'level'} ne "granted"){

undef @imegs;


}

###

if($USER{'sbanned'} eq "yes"){

do "$root/inc/commands/sbanned.inc";

dbmclose(%USER);

exit;

}

dbmclose(%USER);

if(length($DATA{'msg'}) > 400){

$errors = " Error, you can not post longer message than 400 characters.";


undef $DATA{'msg'};

}

foreach $ugh(@nonowords){

if($DATA{'msg'} =~ /$ugh/i){


$errors = " Error sending message, not allowed.";


undef $DATA{'msg'};

          }

}


if($DATA{'msg'} =~ /^\/link/i or $DATA{'msg'} =~ /^\/img/i or $DATA{'msg'} =~ /^\/pic/i){



}else{

@msgs = split(/\s+/,$DATA{'msg'});

foreach $mess (@msgs){

if (length($mess) > 50){


$errors = " Error, you can not post words longer than 50 characters.";

undef $DATA{'msg'};

}}

}





$data_msg = $DATA{'msg'};


$DATA{'msg'} =~ s/\s+\s+/ /ig;



if ($DATA{'msg'} eq ' '){$bypass = 1;}



$DATA{'msg'} =~ s/\</&lt\;/ig;

$DATA{'msg'} =~ s/\>/&gt\;/ig;

$DATA{'msg'} =~ s/\\/\_/ig;

$DATA{'msg'} =~ s/\n+//ig;

$DATA{'msg'} =~ s/^\s+//ig;



if($muted == 1){


if($DATA{'msg'} =~ /^\/rose5/ or $DATA{'msg'} =~ /^\/rose/ or $DATA{'msg'} =~ /^\/link/ or $DATA{'msg'} =~ /^\/d/ or $DATA{'msg'} =~ /^\/\// or $DATA{'msg'} && $DATA{'msg'} !~ /^m\b/ && $DATA{'msg'} !~ /^\//){

undef $DATA{'msg'};

$errors = " Error, you are not allowed to post in public. However you can still chat in private.";

		}


if($DATA{'msg'} eq "m"){

undef $DATA{'msg'};

$errors = " Error, you are not allowed to post in public. However you can still chat in private.";

		}





}





if($summoner ne ""){

$command = "\/dosummonstuff";

require "$root/cgi/commands/command.cgi";

exit;

}


if($room ne $DATA{'room'}){

$command = "\/changerooms";

require "$root/cgi/commands/command.cgi";

exit;

}



##CHECK COMMAND!
################################################################################################









@messsage = split(/\s+/,$DATA{'msg'});

$command = @messsage[0];

foreach $ik(@imegs){

if($command eq $ik){

$byepass = 1;
      }
}


if($bypass != 1 && $byepass != 1){

if($command =~ /^\// or $command =~ /^\/\// or $command eq 'm' && @messsage[1] ne ''){

do "$root/cgi/commands/command.cgi";

exit;

}

}


if($fr eq "yes"){

dbmopen(%USER,"$root/online/users/$DATA{'n'}.db",0777);

undef $USER{'fr'};

dbmclose(%USER);

print "Content-type: text/html\n\n";

require "$root/inc/print_ann.inc";

exit;

}

#####################################################################
####################### IMAGES ######################################

foreach $nrimg(@imegs){

$DATA{'msg'} =~ s/$nrimg\b/<img src=\"\/img$nrimg.gif\">/g;



}


#####################################################################
#####################################################################

$z = 0;

@message = split(/\s+/,$DATA{'msg'});

foreach $key(@message){

if($key =~ /<img/){

$z++;

}


if($key =~ /^\/bo/ && length($key) > 3){

$key = substr($key,3,length($key));

$key = "<b>$key</b>";

}elsif($key =~ /^\/r/ && length($key) > 2){

$key = substr($key,2,length($key));

$key = "<font color=\"red\">$key</font>";

}elsif($key =~ /^\/un/ && length($key) > 3){

$key = substr($key,3,length($key));

$key = "<u>$key</u>";

}elsif($key =~ /^\/g/ && length($key) > 2){

$key = substr($key,2,length($key));

$key = "<font color=\"green\">$key</font>";

}elsif($key =~ /^\/bl/ && length($key) > 3){

$key = substr($key,3,length($key));

$key = "<blink>$key</blink>";

}elsif($key =~ /^\/y/ && length($key) > 2){

$key = substr($key,2,length($key));

$key = "<font color=\"yellow\">$key</font>";


}elsif($key =~ /^\/it/ && length($key) > 3){

$key = substr($key,3,length($key));

$key = "<i>$key</i>";

}

next;

}

foreach $key(@message){

if($key =~ /^\//){

$a_key = $key;

$a_key =~ s/^\///ig;


$one_key = substr($a_key,0,6);

if(length($key) > 8 && $one_key !~ /[\W]/){

$a_key = substr($a_key,6,length($a_key));

$key = "<font color=\"$one_key\">$a_key</font>";

}

}
}


if($z > 5){

$errors = " Error, you can not post more than 5 images per message.";

}

foreach $yay(@badwords){

if($DATA{'msg'} =~ /$yay/i && !-e "$root/online/locked/$room.txt"){


$errors = " Error sending message, not allowed.";

          }

}



if($DATA{'msg'} ne '' && $errors eq '' && $bypass ne 1){

open(ENTRIES, ">>$root/online/rooms/$room.txt");

flock(ENTRIES,2);

if($nickname){   

print ENTRIES "<!--$realnick--> <font color=\"\#000000\">\[</font>$nickname$DATA{'n'}</a><font color=\"\#000000\">\]</font><font size=\"1\" color=\"$iback\">i</font> $scolor@message$ecolor<br>\n";
 
}else{

print ENTRIES "<!--$realnick--> <font color=\"\#000000\">\[</font><A style=\"text-decoration: none\; color: $nickcolor\; font-family: $nicktype\" href=\"javascript:m('$DATA{'n'}')\"><b>$DATA{'n'}</b></a><font color=\"\#000000\">\]</font><font size=\"1\" color=\"$iback\">i</font> $scolor@message$ecolor<br>\n";

}


close(ENTRIES);

}


if($frames eq "yes") {

print "Expires: now\n"; 
print "Pragma: no-cache\n";
print "Cache-Control: no-cache\n"; 
print "Content-type: text/html\n\n";

require "$root/inc/print_header.inc";

require "$root/inc/print_room.inc";

if($print_frames_ann == 1){

require "$root/inc/print_ann.inc";

undef $print_frames_ann;
}

require "$root/inc/print_footer.inc";

}else{

print "Content-type: text/html\n\n";


require "$root/inc/print_header.inc";

require "$root/inc/print_room.inc";

require "$root/inc/print_footer.inc";

}




sub data {
$request_method = $ENV{'REQUEST_METHOD'};
if ($request_method eq "GET") {
        $form_info = $ENV{'QUERY_STRING'};
} else {
        $size_of_form_information = $ENV{'CONTENT_LENGTH'};
        read (STDIN, $form_info, $size_of_form_information);
}
@key_value_pairs = split (/&/, $form_info);
foreach $key_value (@key_value_pairs) {
        ($key, $value) = split (/=/, $key_value);

        $value =~ tr/+/ /;
        $value =~ s/%([\dA-Fa-f][\dA-Fa-f])/pack ("C", hex ($1))/eg;
        if (defined($DATA{$key})) {
                $DATA{$key} = join (", ", $DATA{$key}, $value);
        } else {
                $DATA{$key} = $value;
        }
}
}
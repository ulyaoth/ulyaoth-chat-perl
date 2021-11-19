#!/usr/bin/perl

@nick = split(/\s+/, $DATA{'msg'});

$newnick = @nick[1];

@arab = ("Α","Θ","Κ","Λ","Μ","Ν","Ξ","Ο","δ","Ρ","Σ","Τ","Υ","Φ","Ψ","Ω","Ϊ","Ϋ","ά","έ","ή","ί","α","γ","δ","ζ","ν","ΐ","Β","Γ","Δ","Ε","Ζ","Η","Ι","Π","Φ","Ò","ΰ","ε","ζ","η","θ","ι","κ","λ","μ","ν","ξ","ο");

#Η Θ Κ Λ Μ Ν Ξ Ο Π Ρ Ò Σ Τ Υ Φ Ψ Ω Ϊ Ϋ έ ή ί α γ δ εά ζ ν

#$nn = $newnick;

#foreach $q (@arab) {

#if ($nn =~ /$q/i) {

#$nn =~ s/$q//i;


#   }
#}


#if ($nn =~ /\W/ && $nn) {

if ($newnick =~ /[^a-zA-Z0-9_\Α\Θ\Κ\Λ\Μ\Ν\Ξ\Ο\δ\Ρ\Σ\Τ\Υ\Φ\Ψ\Ω\Ϊ\Ϋ\έ\ή\ί\α\γ\δ\ζ\ν\ΐ\Β\Γ\Δ\Ε\Ζ\Η\Ι\Π\Φ\Ò\ΰ\ε\ζ\η\θ\ι\κ\λ\μ\ν\ξ\ο]/i) {

$errors = " Error, invalid nickname, nickname may contain A-Z, a-z and 0-9 characters only."; 

        return $errors;
exit;

}

#$newnick =~ s/[^\w\Α\Θ\Κ\Λ\Μ\Ν\Ξ\Ο\δ\Ρ\Σ\Τ\Υ\Φ\Ψ\Ω\Ϊ\Ϋ\έ\ή\ί\α\γ\δ\ζ\ν\ΐ\Β\Γ\Δ\Ε\Ζ\Η\Ι\Π\Φ\Ò\ΰ\ε\ζ\η\θ\ι\κ\λ\μ\ν\ξ\ο]//ig;
#|Α|Θ|Κ|Λ|Μ|Ν|Ξ|Ο|δ|Ρ|Σ|Τ|Υ|Φ|Ψ|Ω|Ϊ|Ϋ|έ|ή|ί|α|γ|δ|ζ|ν|ΐ|Β|Γ|Δ|Ε|Ζ|Η|Ι|Π|Φ|Ò|ΰ|ε|ζ|η|θ|ι|κ|λ|μ|ν|ξ|ο

$newnick = substr($newnick,0,15);


if($newnick eq $DATA{'n'}){


$errors = " Error, nickname <b>$newnick</b> already in use."; 

        return $errors;
exit;

}


if (!$newnick or $newnick =~ /db/i) {

$errors = "Syntax: /nick [nick]"; 

return $errors;

exit;
}


if($level >= 1){



if ($newnick =~ /$realnick/i && $newnick ne $realnick && length($newnick) eq length($realnick)){

$errors = " Error , nickname <b>$newnick</b> reserved by an Operator.";

return $errors;

exit;

        }

}





opendir(RD, "$root/ops/ops/");


flock(RD,2);


foreach $entry(sort(grep !/^\./, readdir RD)){


$entry =~ s/.db//ig;

if ($newnick =~ /$entry/i && $realnick ne $entry && length($entry) eq length($newnick)){



$errors = " Error , nickname <b>$newnick</b> reserved by an Operator!!";




return $errors;





exit;

		}

}

closedir(RD);







foreach $word(@badwords){

if($newnick =~ /$word/i){

 $errors = " Error, invalid nickname."; 



        return $errors;

exit;

}
}


#if(-e "$root/online/users/$newnick.db"){

# $errors = " Sorry, nickname <b>$newnick</b> already in use."; 

#   return $errors;
#}


opendir(RD, "$root/online/users");

@files = readdir (RD);

closedir(RD);

    foreach $entry (sort @files) {


        if ($entry ne '.' && $entry ne '..') {

                $entry =~ s/.db//;

               
if($newnick =~ /^$entry$/i && !-e "$root/ops/ops/$newnick.db") {

$errors = " Sorry, nickname <b>$newnick</b> already in use."; 


   return $errors;


} 

}
}











dbmopen(%USER,"$root/online/users/$DATA{'n'}.db",0777);



$oldnicktime = $USER{'timenick'};



dbmclose(%USER);



$ctime = $time - $oldnicktime;





if ($ctime < 30){



$errors =" Sorry, you must wait 30 seconds between nickname changes.";




return $errors;



exit;



}







open(NICKROOM,">>$root/online/rooms/$room.txt");



 flock(NICKROOM,2);





print NICKROOM "<!--servermsg--> *** <B>$DATA{'n'}</b> is now known as <b>$newnick</b>.<br>\n";



close(NICKROOM);





dbmopen(%USER,"$root/online/users/$DATA{'n'}.db",0777);



$USER{'nick'} = "<A HREF=\"javascript:m('$newnick')\">$newnick</a>";





dbmclose(%USER);



if($level >= 10){



rename("$root/online/action/$DATA{'n'}.txt","$root/online/action/$newnick.txt");

}



rename("$root/online/pm/$DATA{'n'}.txt","$root/online/pm/$newnick.txt");



rename("$root/online/users/$DATA{'n'}.db","$root/online/users/$newnick.db");





$DATA{'n'} = $newnick;



dbmopen(%USERR,"$root/online/users/$DATA{'n'}.db",0777);





$USERR{'timenick'} = $time;



dbmclose(%USERR);





if($level >= 1){



open(LASTNICK,">$root/online/lastnick/$realnick.txt");



print LASTNICK "$DATA{'n'}\|\"\'\|$DATA{'room'}";



close(LASTNICK);

}



if($frames eq 'yes'){



$mkframe = 1;



}





$bypass = 1;





return $bypass;

return $mkframe;
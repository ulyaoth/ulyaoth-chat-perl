#!/usr/bin/perl

 
if ($command eq '/editann' && $level < $admin_rank){
                
 $errors = "Error, command $command not recognized, please use /help for a list of commands.";

 return $errors;

exit;

       }


@editann = split(/\s+/, $DATA{'msg'});

@editann[1] =~ s/[^\w]//g;

if(!@editann[1]){

print "Content-type: text/html\n\n";

require "$root/inc/print_header.inc";

open (ANNCHECK,"$root/boards/loginann.txt");

flock(ANNCHECK,2);

@any = <ANNCHECK>;

close(ANNCHECK);

$v = 0;

foreach $ann(@any){

$v++;

($ann1,$ann2)=split(/\|\"\'\|/,$ann);

$ann2 =~ s/^\<!-- (([^ >]|\n)*) -->//ig;

print "<b><a href=\"$location?n=$DATA{'n'}&id=$DATA{'id'}&room=$room&msg=/editann+$ann1\">DEL</a></b> | $ann2";

}

print "<p>TOTAL: <b>$v</b> announcement(s).<br>\n";

require "$root/inc/check_pm.inc";

require "$root/inc/print_footer.inc";

exit;

}

if(length(@editann[1]) > 10 or length(@editann[1]) < 10){

$errors = "Error, command $command not recognized, please use /help for a list of commands.";

return $errors;

exit;

}



open(DEL,"$root/boards/loginann.txt");
 
flock(DEL,1);

@dell = <DEL>;

close(DEL);

open(DEL2,">$root/boards/loginann.txt");

flock(DEL2,2);

$f = 0;

foreach $mail(@dell){

if($mail !~ /@editann[1]/){

   print DEL2 $mail;

  }


}

close(DEL2);


$errors = " Login announcement successfuly deleted.";

return $errors;


exit;
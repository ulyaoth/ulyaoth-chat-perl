#!/usr/bin/perl


@ignore = split(/\s+/,$DATA{'msg'});
            
if(!@ignore[1]){

dbmopen(%USER,"$root/online/users/$DATA{'n'}.db",0777);

if($USER{'ignore_all'}){

undef $USER{'ignore_all'};

$errors = " You are now accepting all private messages.";

dbmclose(%USER);

return $errors;

exit;

}else{

$USER{'ignore_all'} = "all";

$errors = " You are now ignoring all private messages.";

dbmclose(%USER);

return $errors;

exit;


              }


}


#########################################################################################


if(@ignore[1] eq $DATA{'n'}){


$errors = " Syntax: /ig [nick].";

return $errors;

exit;


}

##########################################################################################


if(!-e "$root/online/users/@ignore[1].db" && @ignore[1] ne '-'){


$errors = " Error, ignore failed , user <b>@ignore[1]</b> not found.";

return $errors;

exit;

}


if(@ignore[1] eq '-' && @ignore[2] eq ''){

$errors = " Syntax: /ig [nick] to add a user, /ig - [nick] to remove a user, /ig to ignore all private messages (toggle).";

return $errors;

exit;

}






if(@ignore[1] eq '-' && @ignore[2] ne ''){

open(IGN,"$root/online/ig/$DATA{'n'}.txt");
 
@ign = <IGN>;

close(IGN);

open(IGN2,">$root/online/ig/$DATA{'n'}.txt");

$r = 0;

$d= 0;

  foreach $i(@ign){

$r++;

chop($i);

if($i ne @ignore[2]){

$d++;

   print IGN2 "$i\n";

  }
 }

close(IGN2);


if($d == $r){

$errors = " Error, user <b>@ignore[2]</b> is not on your ignore list.";

return $errors;
exit;

}else{


$errors = " User <b>@ignore[2]</b> removed from ignore list.";

return $errors;
exit;



}
}


open(IG,"$root/online/ig/$DATA{'n'}.txt");

@ig = <IG>;

close(IG);

foreach $line(@ig){

chop($line);

if($line eq @ignore[1]){

$errors = " Error, user <b>@ignore[1]</b> is already on your ignore list.";

return $errors;

exit;

}}

open(IGNORE,">>$root/online/ig/$DATA{'n'}.txt");

print IGNORE "@ignore[1]\n";

close(IGNORE);

$errors = " User <b>@ignore[1]</b> added to ignore list.";

return $errors;

exit;
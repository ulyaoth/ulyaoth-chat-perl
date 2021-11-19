#!/usr/bin/perl


if($command eq '/wait' && $level < 1){

$errors = " Error, command $command not recognized, please use /help for a list of commands.";
   
return $errors;

exti;
     
}



@wait = split(/\s+/,$DATA{'msg'});
            

unless(@wait[1]){

open(WAIT,"$root/wait/$realnick.txt");

@wa = <WAIT>;

close(WAIT);

$errors = " Syntax: /wait [nick] to add. /wait - [nick] to remove.<br> Current Wait list: @wa";

return $errors;

exit;

}

# remove

if(@wait[1] eq '-' && @wait[2] ne '' && @wait[2] !~ /[\W]/ && length(@wait[2]) < 14){

open(WAITME,"$root/wait/$realnick.txt");
 
@waitme = <WAITME>;

close(WAITME);

open(WAITT,">$root/wait/$realnick.txt");

  foreach $i(@waitme){

chop($i);

  if($i ne @wait[2]){

   print WAITIT "$i\n";

  }
 }


close(WAITIT);

$errors = " User <b>@wait[2]</b> removed from Wait List.";

return $errors;

exit;

}
#

if(@wait[1] eq $realnick or @wait[1] =~ /[\W]/ or length(@wait[1]) > 14){

$errors = " Syntax: /wait [nick] to add. /wait - [nick] to remove.";

return $errors;

exit;


}





open(A,"$root/wait/$realnick.txt");

@a = <A>;

close(A);

foreach $line(@a){

chop($line);

if($line eq @wait[1]){

open(WAIT,"$root/wait/$realnick.txt");

@wa = <WAIT>;

close(WAIT);

$errors = " User <b>@wait[1]</b> is already on your wait list.<br> Current Wait List: @wa";

return $errors;

exit;

}}



open(C,">>$root/wait/$realnick.txt");

print C "@wait[1]\n";

close(C);

open(WAIT,"$root/wait/$realnick.txt");

@wa = <WAIT>;

close(WAIT);

$errors = " User <b>@wait[1]</b> added to wait list.<br>Current Wait List: @wa";

return $errors;

exit;
#!/usr/bin/perl



@sb = split(/\s+/,$DATA{'msg'});

@sb[1] =~ s/[^\w]//g;

@sb[1] = substr(@sb[1],0,16);

if(@sb[1] eq "CyberSex"){

$errors = " Error, scroll back of CyberSex is not available.";

return $errors;

exit;

}


unless(@sb[1]){

print "Content-type: text/html\n\n";

require "$root/inc/print_header.inc";

open(SBROOM,"$root/online/rooms/$room.txt");

flock(SBROOM,2);

@sbroom = <SBROOM>;

close(SBROOM);

$c = 0;

foreach $line(@sbroom){

$c++;

$line =~ s/^\<!--(([^ >]|\n)*)-->//ig;

print $line;

}

print "SCROLL BACK / <b>$room</b><br>\n";

require "$root/inc/check_pm.inc";

require "$root/inc/print_footer.inc";

exit;
}



if(-e "$root/online/locked/@sb[1].txt" or !-e "$root/online/rooms/@sb[1].txt"){

print "Content-type: text/html\n\n";

require "$root/inc/print_header.inc";

open(SBROOM,"$root/online/rooms/$room.txt");

flock(SBROOM,2);

@sbroom = <SBROOM>;

close(SBROOM);

$c = 0;

foreach $line(@sbroom){


$line =~ s/^\<!--(([^ >]|\n)*)-->//ig;

if($line =~ /@sb[1]/i){

print $line;

$c++;

		}
   
	}

print "SCROLL BACK / <b>$room</b> (matching $c lines).<br>\n";

require "$root/inc/check_pm.inc";

require "$root/inc/print_footer.inc";

exit;


}


print "Content-type: text/html\n\n";

require "$root/inc/print_header.inc";

open(SBROOM,"$root/online/rooms/@sb[1].txt");

flock(SBROOM,2);

@sbroom = <SBROOM>;

close(SBROOM);


foreach $line(@sbroom){


$line =~ s/^\<!--(([^ >]|\n)*)-->//ig;

print $line;

}

print "SCROLL BACK / <b>@sb[1]</b><br>\n";

require "$root/inc/check_pm.inc";

require "$root/inc/print_footer.inc";

exit 0;
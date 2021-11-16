#!/usr/bin/perl



print "Content-type: text/html\n\n";



require "$root/inc/print_header.inc";


opendir(DIR, "$root/online/rooms/");

flock(DIR,2);

foreach $vv (sort(grep !/^\./, readdir DIR)){
 
if(-e "$root/online/locked/$vv"){

$lock = "L";

}else{

$lock = "U";

	}

$vv =~ s/.txt//;

%hash = (%hash, $vv,$lock);

}

closedir(DIR);


foreach $c(@rooms){

if(-e "$root/online/locked/$c.txt"){

$lock = "L";

}else{

$lock = "U";

	}

%hash = (%hash, $c,$lock);

}


foreach $key (sort (keys %hash)) {

if($hash{$key} eq "U"){

$num = &usr($key);

print "<b><a href=\"$location?n=$DATA{'n'}&room=$room&id=$DATA{'id'}&msg=/join $key\">$hash{$key} : $num : $key</a></b><br>\n";


}else{

$num = &usr($key);


print "<b>$hash{$key} : $num : $key</b><br>\n";


	}
}

print "<p>\nU = UNLOCKED &nbsp;&nbsp; L = LOCKED<br>\n";



require "$root/inc/check_pm.inc";


require "$root/inc/print_footer.inc";


exit 0;



sub usr{

my $rum = shift;

$s = 0;

opendir(DIR,"$root/online/users/");

foreach $n (sort(grep !/^\./, readdir DIR)){

$n =~ s/.db//ig;

dbmopen(%D,"$root/online/users/$n",0777);

if($D{'room'} eq $rum){

$s++;

			}
dbmclose(%D);


}

return $s;


}













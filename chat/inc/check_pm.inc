#!/usr/bin/perl


&chop_private;

       open(FILE,"$root/online/pm/$DATA{'n'}.txt");

                @contents = <FILE>;

 close(FILE);

open(CRASH,"$root/online/pm/$DATA{'n'}.txt");

flock (CRASH,2);

@pri = <CRASH>;

close (CRASH);

$i = 0;

foreach $lin (@pri) {

$i++;

}




if ($i > 0) {

if($i > 25 && $frames ne 'yes'){

#print "<a name=\"b\"></a>\n";

}

print "<hr>\n";

foreach $line(@pri){

@two = split(/\s+/,$line);

$line =~ s/^\<!-- (([^ >]|\n)*) -->//ig;

$line =~ s/\s+\s+/ /ig;
$line =~ s/^\s+//ig;

print $line;

}
}





sub chop_private{

open(PRIVATE,"$root/online/pm/$DATA{'n'}.txt");
flock (PRIVATE,2);
@pri = <PRIVATE>;
close (PRIVATE);

open(PRIVATE,">$root/online/pm/$DATA{'n'}.txt");
flock(PRIVATE,2);

foreach $line (@pri) {
@one = split(/ /,$line);

if ($time-$one[1] > $msg_time) {


}else{
print PRIVATE "$line";

}

}
close(PRIVATE);

}

return true;

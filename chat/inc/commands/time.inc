#!/usr/bin/perl

opendir(DIR,"$root/time/");

flock(DIR,2);

@dir = readdir(DIR);

closedir(DIR);


undef %hash;

foreach $f (@dir) {

if($f ne '..' && $f ne '.'){

open(DAT,"$root/time/$f");

flock(DAT,1);

$t = <DAT>;

#$s = &hms($t);

close(DAT);

$f =~ s/\.dat//ig;

$t = &hms($t);

%hash = (%hash,$t,$f);

#push(%hash,$t,$f);
		

            }
  
  }




###############

print "Content-type: text/html\n\n";

require "$root/inc/print_header.inc";
print <<"(END HTML FOOTER)";

<center>      <table border="1" width="75%" height="1" bgcolor="#E4EEF1" bordercolor="black">
        <tr>
          <td width="100%" height="1" align="center" bgcolor="#DADADA" colspan="2">
            <b>Top Chatters for the month of: <font color="green">$amonth</font><b>
          </td>
        </tr>
        <tr>
          <td width="50%" height="1" align="center" bgcolor="#FEF5CD">
            <b>NickName</b>
          </td>
          <td width="50%" height="1" align="center" bgcolor="#FEF5CD">
            <b>H:M:S (H=Hours, M=Minutes, S=Seconds)</b>
          </td>
        </tr>
(END HTML FOOTER)

$c = 0;



@keys = reverse(sort keys %hash);

foreach (@keys) {

 $c++;

if($c < 21){

if($c == 1){


#print "$_=>$hash{$_}, "

print "<tr><td width=\"50%\" height=\"1\" align=\"center\"><b><font color=\"red\">$hash{$_}</b></td>\n";


print "<td width=\"50%\" height=\"1\" align=\"center\"> <font color=\"red\"><b>$_</b></td></tr>\n\n";

}else{

print "<tr><td width=\"50%\" height=\"1\" align=\"center\"><b><font color=\"blue\">$hash{$_}</b></td>\n";




print "<td width=\"50%\" height=\"1\" align=\"center\"> <font color=\"blue\"><b>$_</b></td></tr>\n\n";



}

       
}
next;
    }

print "</table></center>\n<p>\n<p>\n\n";
  


require "$root/inc/check_pm.inc";



require "$root/inc/print_footer.inc";


################


sub hms {
    my $seconds = shift;
    my $minutes = int $seconds / 60;
    my $hours = int $minutes / 60;
    $minutes = $minutes % 60;
    $seconds = $seconds % 60;
    return sprintf "%04d:%02d:%02d", $hours,$minutes,$seconds;
}


exit;



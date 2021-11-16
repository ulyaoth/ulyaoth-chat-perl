#!/usr/bin/perl



if ($level < 1){

                

        $errors = " Error, command $command not recognized, please use /help for a list of commands.";

        }



@vote = split(/\s+/, $DATA{'msg'});


unless(@vote[1]){

opendir(DIR,"$root/vote");

flock(DIR,2);

@dir = readdir(DIR);

closedir(DIR);


foreach $f(@dir){

if($f ne '..' && $f ne '.'){

$f =~ s/.dat//ig;

open(DT,"$root/vote/$f.dat");

flock(DT,1);

$t = <DT>;

close(DT);

%h = (%h,$f,$t);

		}
next;

}

###############

print "Content-type: text/html\n\n";

require "$root/inc/print_header.inc";
print <<"(END HTML FOOTER)";

<center>      <table border="1" width="75%" height="1" bgcolor="#E4EEF1" bordercolor="black">
        <tr>
          <td width="100%" height="1" align="center" bgcolor="#DADADA" colspan="2">
            <b>Mr and Miss $title for the month of: <font color="green">$amonth</font><b>
          </td>
        </tr>
        <tr>
          <td width="50%" height="1" align="center" bgcolor="#FEF5CD">
            <b>NickName</b>
          </td>
          <td width="50%" height="1" align="center" bgcolor="#FEF5CD">
            <b>Votes</b>
          </td>
        </tr>
(END HTML FOOTER)


 foreach $key (reverse(sort(keys %h))){


print "<tr><td width=\"50%\" height=\"1\" align=\"center\"><b><font color=\"blue\">$key</b></td>\n";

print "<td width=\"50%\" height=\"1\" align=\"center\"> <font color=\"blue\"><b>$h{$key}</b></td></tr>\n\n";


    }

print "</table></center>\n<p>\n<p>\n\n";
  
require "$root/inc/check_pm.inc";

require "$root/inc/print_footer.inc";

exit;

}


if(!-e "$root/ops/ops/@vote[1]"){

$errors = " Error, user <b>@vote[1]</b> is not an Operator.";

return $errors;

exit;
}


dbmopen(%V,"$root/ops/ops/$realnick",0777);

if($V{'voted'} eq $amonth){

dbmclose(%V);

$errors = " Error, you've already voted for this month ($amonth).";

return $errors;

exit;

}

$V{'voted'} = $amonth;

dbmclose(%V);

open(VOTE,"$root/vote/@vote[1].dat");

flock(VOTE,1);

$old_vote = <VOTE>;

close(VOTE);

$old_vote ++;

open(VOT,">$root/vote/@vote[1].dat");

flock(VOT,2);

print VOT $old_vote;

close(VOT);

$errors = " You have successfuly voted for Operator <b>@vote[1]</b> for month of <b>$amonth</b>.";

return $errors;

exit;






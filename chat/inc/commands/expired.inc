
if ($level < $admin_rank){

$errors = " Error, command $command not recognized, please use /help for a list of commands.";

return $errors;

exit;

}



opendir(OP,"$root/ops/ops/");

flock(OP,2);

@array = readdir(OP);

closedir(OP);




if ($emonth < 10) { $emonth = "0$emonth"; }  

$ssh = $year . $emonth . $day;


foreach $o (sort @array) {

if($o ne '.' && $o ne '..'){

$o =~ s/.db//;

dbmopen(%A,"$root/ops/ops/$o",0777);

($xday,$xmonth,$xyear) = split(/\//,$A{'ops_end'});

$stt = $A{'ops_began'};

dbmclose(%A);

if ($xmonth < 10) { $xmonth = "0$xmonth"; }  

if ($xday < 10) { $xday = "0$xday"; }

$en = $xyear . $xmonth . $xday;

if($ssh > $en){

undef $q;
undef $expyear;
undef $expmonth;
undef $expday;

$r++;


$expyear = $year - $xyear;
$expmonth = $emonth - $xmonth;
$expday = $day - $xday;

$q = "year:".$expyear."month:".$expmonth."day:".$day;

$errors .= "$o expired: $q<br>";

				}
			}
	}

$errors .= " Total: $r expired ops.";

return $errors;
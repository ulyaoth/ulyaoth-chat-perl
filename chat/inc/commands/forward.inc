#!/usr/bin/perl


@forward = split(/\s+/, $DATA{'msg'});


if(@forward[1] eq ''){

$errors = " Syntax: /forward [nick].";

return $errors;

exit;
}



if(!-e "$root/ops/ops/@forward[1]"){


$errors = " Error, <b>@forward[1]</b> is not an Operator.";

return $errors;

exit;

}

open(FFW,"$root/online/pm/$DATA{'n'}.txt");

@fw = <FFW>;

close(FFW);

open(WW,">>$root/online/pm/@forward[1].txt");


print WW "<!-- $time --> *** Beginning forward from <b>$DATA{'n'}</b>.<br>\n";

foreach $line(@fw){

@two = split(/\s+/,$line);

$line =~ s/@two[0]//ig;
$line =~ s/@two[1]//ig;
$line =~ s/@two[2]//ig;
$line =~ s/\s+\s+/ /ig;
$line =~ s/^\s+//ig;

print WW "<!-- $time --> $line";

}

print WW "<!-- $time --> *** End forward from <b>$DATA{'n'}</b>.<br>\n";

close(WW);


$errors = " Messages forwarded to Operator <b>@forward[1]</b>.";







#!/usr/bin/perl



@comment = split(/\s+/, $DATA{'msg'});



if(!@comment[1]){



dbmopen(%USER,"$root/online/users/$DATA{'n'}.db",0777);



undef $USER{'comment'};



dbmclose(%USER);





$errors = " Removed comment.";



return $errors;



exit;

}



$DATA{'msg'} =~ s/^\/comment//ig;





if (length($DATA{'msg'}) > 36){



$DATA{'msg'} = substr($DATA{'msg'},0,36);



}



dbmopen(%USER,"$root/online/users/$DATA{'n'}.db",0777);



$USER{'comment'} = $DATA{'msg'};



dbmclose(%USER);




$errors = " Comment set: $DATA{'msg'}";



return $errors;



exit;
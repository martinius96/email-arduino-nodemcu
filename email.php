<?php
$message= "Ahoj svet!";
$message= wordwrap($msg,70);
mail("addressofreceiver@hismail.com","Subject",$message);
?>

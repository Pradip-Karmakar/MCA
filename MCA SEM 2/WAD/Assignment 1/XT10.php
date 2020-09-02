<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Assignment 1 XT10</title>
	<link rel="stylesheet" type="text/css" href="main.css">
</head>
<body>
	<div class="box">
	<?php

		$milk = array ("Tazza" => 26, "Shakti" => 22, "Gold" => 30);
		echo "Sort by Price<br>";
		$pricesort = $procuct =  $milk;
		asort($pricesort);
		foreach($pricesort as $key=>$value)
		{
			echo $key . " : " . $value . "<br>"; 
		}

		echo "<br> Sort By Name <br>";

		ksort($procuct);
		foreach($procuct as $key=>$value)
		{
			echo $key . " : " . $value . "<br>"; 
		}
	?>
	</div>
</body>
</html>


<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Assignment 1 XT3</title>
	<link rel="stylesheet" type="text/css" href="main.css">
</head>
<body>
	<div class="box">
		<form method="POST">
			<div>
				<input type="number" name="min" autocomplete="off" placeholder="Minimum">
			</div>
			<div>
				<input type="number" name="max" autocomplete="off" placeholder="Maximum">
			</div>
			<div>
				<button class="submit" name="submit"> Submit </button>
			</div>
		</form>
	
		<?php
		if (isset($_POST['submit'])) {
			$min = $_POST['min'];
			$max = $_POST['max'];	
			if($min < 1) {
				echo "<br>Minimum Value must be greater than 0";
				die();
			}	
			else if($min > $max){
				echo "<br>Maximum value must be greater than mininum value";
				die();
			}

			for ($i = $min; $i <= $max ; $i++) { 
				echo "<br> The radius of " .$i. " is " . (3.14 * $i * $i);
			}
		}
		?>
	</div>
</body>
</html>
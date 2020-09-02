<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Assignment 1 XT9</title>
	<link rel="stylesheet" type="text/css" href="main.css">
</head>
<body>
	<div class="box">
	<?php
		$arr = array("1. Chana Masala","2. Dal Makhani","3. Chole Bhature","4. Kadai Paneer","5. Aloo Paratha","6. Chicken Leg Piece");
		$i = 2;
		foreach ($arr as $value) {
			if($i % 2) {
				echo "<br>" . $value;
			}
			$i++;
		} 
		?>
	</div>
</body>
</html>



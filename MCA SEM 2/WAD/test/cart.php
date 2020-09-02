<?php
session_start();
require_once('dataclass.php');
$dc = new Dataclass();
$total = 0;
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Checkout</title>
    <link rel="stylesheet" href="main.css">
</head>
<body>
    <div class="cart">
        <h1>Cart</h1>
        <form method="POST">
            <div class="innertable">    
                <table>
                    <tr>
                        <th>Product Name</th>
                        <th>Price</th>
                        <th>Quantity</th>
                        <th>Total</th>
                    </tr>
                    <?php 
                        $get = $dc->getTable("select * from cart");
                        while ($rw=mysqli_fetch_assoc($get))
                        {
                    ?>  
                        <tr>
                            <td><?= $rw['pro_name'] ?></td>
                            <td><?= $rw['price'] ?></td>
                            <td><?= $rw['qty'] ?></td>
                            <td><?= $rw['price'] * $rw['qty'] ?></td>
                        </tr>
                    <?php
                        $total += $rw['price'] * $rw['qty'];
                        }
                    ?>
                    <tr>
                        <th colspan="3">Total</th>
                        <th><?= $total ?></th>
                    </tr>  
                </table>
            </div>
            <div>
                <input type="submit" value="Home" name="submit" class="form_button">
                <?php
                    if(isset($_POST['submit']))
                    {
                        header("location:shop.php");
                    }
                ?>
            </div>
        </form>
    </div>
</body>
</html>


<?php
session_start();
include 'connection.php';

if(isset($_SESSION['email'])) {?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.1.1/jquery.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
    <title>Uncle nostalgia</title>
    <link rel="stylesheet" href="css/styles-homeUsuario.css">
</head>
<body>
    <header>
        <nav class="navbar navbar-inverse navbar-static-top" role="navigation">
            <div class="container">
                <div class="navbar-header">
                    <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#navegacion-fm">
                        <span class="sr-only">Desplegar / Ocultar Menú</span>
                        <span class="icon-bar"></span>
                        <span class="icon-bar"></span>
                        <span class="icon-bar"></span>
                    </button>
                    <a href="homeUsuario.php" class="navbar-brand">:')</a>
                </div>
                <!-- Inicia menú -->
                <div class="collapse navbar-collapse" id="navegacion-fm">
                    <ul class="nav navbar-nav">
                        <li class="active"><a href="exp.php">Explorar</a></li>
                        <li class="dropdown">
                            <a href="#" class="dropdown-toggle" data-toggle="dropdown" role="button">
                            <?php 
                                echo $_SESSION['nickname'];
                            ?>
                            <span class="caret"></span></a>
                            <ul class="dropdown-menu" role="menu">
                                <li><a href="homeUsuario.php"><span class="glyphicon glyphicon-user"></span> Perfil</a></li>
                                <li><a href="logout.php"><span class="glyphicon glyphicon-log-out"></span> Log out</a></li>
                            </ul>
                        </li>
                    </ul>
                </div>
            </div>
        </nav>
    </header>
    <div class="jumbotron">
        <div class="container text-center">
            <h1>My Portfolio</h1>      
            <p>Some text that represents "Me"...</p>
        </div>
    </div>
    <div class="main container">
        <div class="row">
            <div class="favoritos col-md-9">
                <div class="page-header">
                    <h3>Mis favoritos</h3>
                </div>
                <div class="row">
                    <div class="col-md-6">
                        <a href="#D1" data-toggle="modal"><img src="img/meliora.jpg" width="100%"></a>
                    </div>
                    <div class="col-md-6">
                        <a href="#D2" data-toggle="modal"><img src="img/sci.jpg" width="100%"></a>
                    </div>
                </div>
            </div>
            <div class="info col-md-3">
                <div class="page-header">
                    <h3>Mi Info!</h3>
                </div>
                <form class="form-group" method="POST" action="update.php">
                    <div class="form-group text-center">
                        <input type="text" class="form-control" id="nombre" name="nombre" placeholder="Nombre" disabled>
                    </div>
                    <div class="form-group text-center">
                        <input type="text" class="form-control" id="apellido" name="apellido" placeholder="Nombre" disabled>
                    </div>
                    <div class="form-group text-center">
                        <input type="text" class="form-control" id="nick" name="nick" placeholder="Nickname" disabled>
                    </div>
                    <div class="form-group text-center">
                        <input type="email" class="form-control" id="email" name="email" placeholder="Email" disabled>
                    </div>
                    <div class="form-group text-center">
                        <input type="password" class="form-control" id="pass" name="pass" placeholder="Password" disabled>
                    </div>
                    <button type="button" id="modificar" class="btn btn-danger btn-block">Modificar</button>
                </form>
            </div>
        </div>
    </div>
    <!-- DISCOS -->
    <div class="modal fade" id="D1">
        <div class="modal-dialog modal-lg">
            <div class="modal-content">
                <!-- header ventana -->
                <div class="modal-header">
                    <button type="button" class="close" data-dismiss="modal" area-hidden="true">&times;</button>
                    <h4 class="modal-title">Ghost BC - Meliora</h4>
                </div>
                <!-- Contenido ventana -->
                <div class="modal-body">
                    <div class="embed-responsive embed-responsive-16by9">
                        <iframe src="https://open.spotify.com/embed/album/74QTwjBLo1eLqpjL320rXX" width="300" height="380" frameborder="0" allowtransparency="true"></iframe>
                    </div>
                </div>
            </div>
        </div>
    </div>
    <div class="modal fade" id="D2">
        <div class="modal-dialog modal-lg">
            <div class="modal-content">
                <!-- header ventana -->
                <div class="modal-header">
                    <button type="button" class="close" data-dismiss="modal" area-hidden="true">&times;</button>
                    <h4 class="modal-title">Chevelle - Sci-fi Crimes</h4>
                </div>
                <!-- Contenido ventana -->
                <div class="modal-body">
                    <div class="embed-responsive embed-responsive-16by9">
                        <iframe src="https://open.spotify.com/embed/album/4yo38BbmUi80kZOqHlRhNH" width="300" height="380" frameborder="0" allowtransparency="true"></iframe>
                    </div>
                </div>
            </div>
        </div>
    </div>
    <footer>
        <div class="container">
            <div class="col-xs-12">
                <h5 class="text-center">&#60;/white_noise&#62;</h5>
            </div>
        </div>
    </footer>
    <script>
        var nickUsr = "<?php echo $_SESSION['nickname'];?>";
        var nombreUsr = "<?php echo $_SESSION['nombre'];?>";
        var apellidoUsr = "<?php echo $_SESSION['apellido'];?>";
        var emailUsr = "<?php echo $_SESSION['email'];?>";
        var passUsr = "<?php echo $_SESSION['pass'];?>";

        document.getElementById("nombre").placeholder = nombreUsr;
        document.getElementById("apellido").placeholder = apellidoUsr;
        document.getElementById("nick").placeholder = nickUsr;
        document.getElementById("email").placeholder = emailUsr;
        document.getElementById("pass").placeholder = passUsr;

        document.getElementById("modificar").addEventListener("click", myFunction);

        function myFunction() {
            document.getElementById("nombre").disabled = false;
            document.getElementById("nombre").value = nombreUsr;

            document.getElementById("apellido").disabled = false;
            document.getElementById("apellido").value = apellidoUsr;

            document.getElementById("nick").disabled = false;
            document.getElementById("nick").value = nickUsr;

            document.getElementById("email").value = emailUsr;
            document.getElementById("pass").value = passUsr;            

            document.getElementById("modificar").className = "btn btn-primary btn-block";
            //document.getElementById("modificar").type = "submit"
        }


    </script>
</body>
</html>
<?php
}else{
    echo '<script> window.location="index.php"; </script>';
}
?>
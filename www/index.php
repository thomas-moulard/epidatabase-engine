<?
	session_start();
	
	include("./parametres/constantes.php");
	$connexion = mysql_connect("$url_bdd" , "$login_bdd" , "$pass_bdd");

	// Liste des onglets
	class Onglet
	{
		var $Libelle;
		var $Page;
	}
	
	$Tabs = Array();
	
	$Tabs[0] = new Onglet();
	$Tabs[0]->Libelle = "Accueil";
	$Tabs[0]->Page = "home.php";
	
	$Tabs[1] = new Onglet();
	$Tabs[1]->Libelle = "Projet";
	$Tabs[1]->Page = "projet.php";
	
	$Tabs[2] = new Onglet();
	$Tabs[2]->Libelle = "Avancement";
	$Tabs[2]->Page = "avancement.php";
	
	$Tabs[3] = new Onglet();
	$Tabs[3]->Libelle = "Téléchargements";
	$Tabs[3]->Page = "telechargements.php";
	
	$Tabs[4] = new Onglet();
	$Tabs[4]->Libelle = "Contact";
	$Tabs[4]->Page = "contact.php";
	
	$Tabs[5] = new Onglet();
	$Tabs[5]->Libelle = "Administration";
	$Tabs[5]->Page = "admin.php";
?>

<html>
	
	<head>
		<title>epi.database - Système de Gestion de Base de Données</title>
		<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
		<link rel=stylesheet href="<?=$racine?>/parametres/style.css" type="text/css">
		
	</head>

	<body>
	
		<center>
		
		<table cellpadding=0 cellspacing=0 width=760>
			<tr>
				<td colspan=3 align="center" background="<?=$racine?>/images/logo.gif" style="background-repeat: no-repeat" width=409 height=133></td>
			</tr>
			<tr>
				<td colspan=3 align="center">
				
					<table cellpadding=0 cellspacing=0 width=100%>
						<tr>
							<td class="notabs">.</td>
							<td>
							<?
							// Affichage des onglets
							$NbTabs = count($Tabs);
							$CurrentTab = 0;
							
							if(isset($_GET['Tab']))
								$CurrentTab = $_GET['Tab'];
								 
							for($i = 0; $i < $NbTabs-1; $i++)
							{
								$State = "off";
								$ColourBack = "#D0D0D0";
								if($i == $CurrentTab) 
								{
									$State = "on";
									$ColourBack = "#F1F1F1";
								}
									
								echo "<td class='tab_".$State."' align='center' onmouseout='this.style.background=\"".$ColourBack."\"' onmouseover='this.style.background=\"#F1F1F1\"'><a href='index.php?Tab=".$i."' class='link_".$State."'>".$Tabs[$i]->Libelle."</a></td>";
								echo "<td width=5 class='notabs'>.</td>";
							}
							$State = "off";
							if($NbTabs == $CurrentTab + 1) 
								$State = "on";
								
							echo "<td class='tab_".$State."' align='center' onmouseout='this.style.background=\"".$ColourBack."\"' onmouseover='this.style.background=\"#F1F1F1\"'><a href='index.php?Tab=".$i."' class='link_".$State."'>".$Tabs[$NbTabs-1]->Libelle."</a></td>";
							?>
							</td>
							<td class="notabs">.</td>
						</tr>
					</table>
				
				</td>
			</tr>
			
			<tr>
				<td class="bordure" width=1></td>
				<td class="contenu" width=740 align="center">
					<?
						// Affichage de la page concernée
						include($Tabs[$CurrentTab]->Page);
					?>
				</td>
				<td class="bordure" width=1></td>
			</tr>
			
			<tr>
				<td colspan=3>
				
					<table cellpadding=0 cellspacing=0 width=100%>
						<tr>
							<td width=15 height=15 background="<?=$racine?>/images/corner_bl.gif"></td>
							<td class="bas" width=730 align="right"><font color="#FF8800">epi</font>database · projet epita 2008</td>
							<td width=15 height=15 background="<?=$racine?>/images/corner_br.gif"></td>
						</tr>
					</table>
				
				</td>
			</tr>
		</table>
		
		</center>
	
	</body>
	
</html>

<?
mysql_close($connexion);
?>
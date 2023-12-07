#include "style.h"

void applyStyles(Ui::MainWindow *ui)
{
    QString button1_style=
            "QPushButton {"
               "    background-color: #3498db;"  // Background color
               "    color: #ffffff;"              // Text color
               "    padding: 5px 10px;"           // Padding around text
               "    font-size: 20px;"             // Font size
               "    border: 1px solid #2980b9;"   // Border color
               "    border-radius: 5px;"          // Border radius for rounded corners
               "}"
               ""
               "QPushButton:hover {"
               "    background-color: #2980b9;"  // Background color on hover
               "    border: 1px solid #3498db;"   // Border color on hover
               "}"
               ""
               "QPushButton:pressed {"
               "    background-color: #1f618d;"  // Background color when pressed
               "    border: 1px solid #2980b9;"   // Border color when pressed
               "}";

    QString button2_style="QPushButton {"
                          "    background-color: #7D0000;"       // New background color
                          "    color: #ffffff;"                  // Text color
                          "    padding: 5px 10px;"
                          "    font-size: 20px;"
                          "    border: 1px solid #7D0000;"       // New border color
                          "    border-radius: 5px;"
                          "}"
                          ""
                          "QPushButton:hover {"
                          "    background-color: #590000;"       // New background color on hover
                          "    border: 1px solid #590000;"       // New border color on hover
                          "}"
                          ""
                          "QPushButton:pressed {"
                          "    background-color: #400000;"       // New background color when pressed
                          "    border: 1px solid #400000;"       // New border color when pressed
                          "}";;
    QString button3_style="QPushButton {"
                          "    background-color: #E7A391;"       // New background color
                          "    color: #ffffff;"                  // Text color
                          "    padding: 5px 10px;"
                          "    font-size: 20px;"
                          "    border: 1px solid #E7A391;"       // New border color
                          "    border-radius: 5px;"
                          "}"
                          ""
                          "QPushButton:hover {"
                          "    background-color: #CC876F;"       // New background color on hover
                          "    border: 1px solid #CC876F;"       // New border color on hover
                          "}"
                          ""
                          "QPushButton:pressed {"
                          "    background-color: #B37259;"       // New background color when pressed
                          "    border: 1px solid #B37259;"       // New border color when pressed
                          "}";
;





     ui->centralWidget->setStyleSheet(
        "QMainWindow {"
        "    background-color: #fc7d7d;"
        "}"
        ""
        "QWidget#centralWidget {"
        "    background-color: #f0f0f0;"
        "}"
    );



    //combobox style
    QString combobox_style= "QComboBox {"
                            "    background-color: #ecf0f1;"  // Background color
                            "    color: #2c3e50;"              // Text color
                            "    border: 1px solid #bdc3c7;"   // Border color
                            "    border-radius: 5px;"          // Border radius for rounded corners
                            "    padding: 3px 8px;"            // Padding around text
                            "    selection-background-color: #3498db;"  // Background color when an item is selected
                            "}"
                            ""
                            "QComboBox::drop-down {"
                            "    border: none;"  // Remove the default drop-down arrow
                            "}"
                            ""
                            "QComboBox::down-arrow {"
                            "    image: url(:/path/to/down_arrow.png);"  // Replace with your own image for the drop-down arrow
                            "}";
//lineEdit style
    QString lineEdit_style= "QLineEdit {"
                            "    background-color: #ecf0f1;"
                            "    border: 1px solid #bdc3c7;"
                            "    padding: 5px;"
                            "    color: #2c3e50;"
                            "    border-radius: 10px;"
                            "}"
                            ""
                            "QLineEdit:hover {"
                            "    border: 1px solid #7f8c8d;"
                            "}"
                            ""
                            "QLineEdit:focus {"
                            "    border: 2px solid #3498db;"
                            "}"
                        ;

//group box style
     QString group_box_style= "QGroupBox {"
                              "    border: 2px solid #3498db;"  // Border color and width
                              "    border-radius: 5px;"          // Border radius for rounded corners
                              "    margin-top: 10px;"            // Top margin
                              "}"
                              ""
                              "QGroupBox::title {"
                              "    subcontrol-origin: margin;"   // Ensure the title is inside the border
                              "    subcontrol-position: top left;"  // Position the title at the top left
                              "    padding: 5px 10px;"            // Padding around the title
                              "    color: #ffffff;"               // Text color of the title
                              "    background-color: #3498db;"    // Background color of the title
                              "    border: 1px solid #3498db;"    // Border color of the title
                              "    border-top-left-radius: 4px;"  // Border radius for the top-left corner of the title
                              "    border-top-right-radius: 4px;" // Border radius for the top-right corner of the title
                              "}";
      ui->le->setStyleSheet(lineEdit_style);
       ui->  cher_veh->setStyleSheet(lineEdit_style);
   //     ui-> l_maintenance ->setStyleSheet(lineEdit_style);
         ui-> l_kilo ->setStyleSheet(lineEdit_style);
          ui-> l_marque ->setStyleSheet(lineEdit_style);
           ui-> l_modele ->setStyleSheet(lineEdit_style);
           ui->   l_immatricule ->setStyleSheet(lineEdit_style);

      ui->poids->setStyleSheet(lineEdit_style);
      ui->volume->setStyleSheet(lineEdit_style);
      //ui->etat->setStyleSheet(lineEdit_style);
      ui->pdf_bar->setStyleSheet(lineEdit_style);
      //ui->Rech->setStyleSheet(lineEdit_style);
         ui->Rech_3->setStyleSheet(lineEdit_style);
    ui->doadd->setStyleSheet(lineEdit_style);

            ui->location_2->setStyleSheet(lineEdit_style);
         QString tabWidget_style ="QTabWidget::pane {"
                                  "    border: 1px solid #bdc3c7;" // Border color
                                  "}"
                                  ""
                                  "QTabBar::tab {"
                                  "    background-color: #3498db;" // Background color of tabs
                                  "    color: #ffffff;"            // Text color of tabs
                                  "      padding: 12px 18px;"
                                  " border-top-left-radius: 10px;"   // Set the radius for the top-left corner
                                          "    border-top-right-radius: 10px;"

                                          // Padding inside each tab
                                  "}"
                                  ""
                                  "QTabBar::tab:selected {"
                                  "    background-color: #2980b9;" // Background color of the selected tab
                                  "}"
                                  ""
                                  "QTabBar::tab:hover {"
                                  "    background-color: #2980b9;" // Background color when hovering over a tab
                                  "}" ;

  ui->widget_2->setStyleSheet(tabWidget_style);
  ui->vehicules->setStyleSheet(tabWidget_style);
    ui->client_tab->setStyleSheet(tabWidget_style);
      ui->tabWidget->setStyleSheet(tabWidget_style);
//**********************

      ui->pdf_label->setStyleSheet(
          "QLabel {"
          "    background-color: #ecf0f1;" // Background color
          "    color: #2c3e50;"
          "    padding: 12px 18px;"// Text color
                       // Padding around text
          "    border: 1px solid #bdc3c7;"  // Border color
          "    border-radius: 5px;"         // Border radius for rounded corners
          "}"
      );
//********************

     ui->combo_2->setStyleSheet(combobox_style);
         ui->combo_3->setStyleSheet(combobox_style);
       ui->combo_4->setStyleSheet(combobox_style);
        ui->combo->setStyleSheet(combobox_style);

       //***************
       ui->groupBox->setStyleSheet(group_box_style);
         ui->group_box_cliens->setStyleSheet(group_box_style);
             ui->groupBox_10->setStyleSheet(group_box_style);
                ui->group_box_vehicule_2->setStyleSheet(group_box_style);

             ui->groupBox_5->setStyleSheet(group_box_style);
   ui->groupBox_6->setStyleSheet(group_box_style);
       ui->groupBox_7->setStyleSheet(group_box_style);
           ui->groupBox_8->setStyleSheet(group_box_style);
            ui-> group_box_vehicule->setStyleSheet(group_box_style);
             ui-> combobox_tri_veh->setStyleSheet(combobox_style);


        ui->stat->setStyleSheet(button1_style);
ui->tri_b->setStyleSheet(button1_style);
 ui->aff->setStyleSheet(button1_style);
 ui->supp->setStyleSheet(button1_style);
 ui->supp->setStyleSheet(button1_style);
 ui->mod1->setStyleSheet(button1_style);
 ui->B_ajouter->setStyleSheet(button1_style);

 ui->B_ajouter_2->setStyleSheet(button2_style);
   ui->clients->setStyleSheet(button2_style);
         ui->commandes->setStyleSheet(button2_style);
     ui->vehicule->setStyleSheet(button2_style);
       ui->livreurs->setStyleSheet(button2_style);
 ui->tmp->setStyleSheet(button3_style);
  ui->aff_tmp->setStyleSheet(button3_style);
   ui->stat_tmp->setStyleSheet(button3_style);
QString tab_style= "QTableView {"
                  "    background-color: #ecf0f1;"  // Background color
                  "    border: 1px solid #3498db;"
        "border-width:2px;"// Border color
                  "    gridline-color: #bdc3c7;"
         // Color of gridlines
                  "}"
                  ""
                  "QHeaderView::section {"
                  "    background-color: #3498db;"  // Background color of header sections
                  "    color: #ffffff;"              // Text color of header sections
                  "    padding: 4px;"                // Padding in header sections
                  "    border: 1px solid #2980b9;"   // Border color of header sections
                  "}"
                  ""
                  "QTableView::item {"
                  "    padding: 5px;"                // Padding around table items
                  "    border-bottom: 1px solid #bdc3c7;"  // Border color at the bottom of each item

                  "}"
                  ""
                  "QTableView::item:selected {"
                  "    background-color: #3498db;"  // Background color of selected items
                  "    color: #ffffff;"
                           // Text color of selected items
                  "}";
QString tab_style1= "QTableView {"
                  "    background-color: #ecf0f1;"  // Background color
                  "    border: 1px solid   #bdc3c7;"   // Border color
                  "    gridline-color:   #bdc3c7;"     // Color of gridlines
                  "}"
                  ""
                  "QHeaderView::section {"
                  "    background-color: #E7A391;"  // Background color of header sections
                  "    color: #ffffff;"              // Text color of header sections
                  "    padding: 4px;"                // Padding in header sections
                  "    border: 1px solid  #bdc3c7;"   // Border color of header sections
                  "}"
                  ""
                  "QTableView::item {"
                  "    padding: 5px;"                // Padding around table items
                  "    border-bottom: 1px solid  rgba(189, 195, 199, 0);"  // Border color at the bottom of each item

                  "}"
                  ""
                  "QTableView::item:selected {"
                  "    background-color: #3498db;"  // Background color of selected items
                  "    color: #ffffff;"
                           // Text color of selected items
                  "}";
       ui->tab_ajout->setStyleSheet(tab_style);
       ui->tab_c->setStyleSheet(tab_style);
       ui->tab_c_2->setStyleSheet(tab_style1);
       ui->tab_vehicule->setStyleSheet(tab_style);
       ui->widget->setStyleSheet(
           "QWidget {"
           "    background-color: #ecf0f1;"  // Background color
           "    color: #2c3e50;"              // Text color
           "    padding: 10px;"               // Padding around content
           "    border: 1px solid #bdc3c7;"   // Border color
           "    border-radius: 5px;"          // Border radius for rounded corners
           "}"
       );

      QString titleStyleSheet =
              "QLabel {"
              "    qproperty-alignment: AlignCenter;"
              "    background-color: rgba(52, 152, 219, 0.6);"  // Transparent background color for the title
              "    color: #ffffff;"                               // Text color
              "    font-size: 24px;"                              // Font size
              "    padding: 10px;"
              "    border-bottom: 2px solid #ffffff;"
              "    border-radius: 6px"
              // Bottom border for separation
              "}";
      QString label1_style="QLabel {"
              "    qproperty-alignment: AlignCenter;"
                           "    background-color:  rgba(231, 163, 145, 0.8);"       // Background color for the content labels
                           "    color: #ffffff;"                  // Text color
                           "    font-size: 20px;"                 // Font size
                           "    padding: 5px 10px;"
                           "    border: 1px solid rgba(189, 195, 199, 0.5);"   // Border with transparency
                           "    border-radius: 5px;"
                           "}";
      ui->add->setStyleSheet(button3_style);
      ui->on_tmp->setStyleSheet(button3_style);
      ui->off_tmp->setStyleSheet(button3_style);
      ui->location->setStyleSheet(button1_style);
ui->menu->setStyleSheet(button2_style);
      ui->combo_etat->setStyleSheet(combobox_style);
       ui->label_8->setStyleSheet(titleStyleSheet);
       ui->suivi->setStyleSheet(titleStyleSheet);
         ui->liste->setStyleSheet(titleStyleSheet);
       ui->label_57->setStyleSheet(label1_style);
           ui->label_58->setStyleSheet(label1_style);
               ui->label_59->setStyleSheet(label1_style);
               ui->map->setStyleSheet(
                   "QWidget {"
                   "    background-color: #3498db;"
                   "    border: 2px solid #2980b9;"
                   "    border-radius: 5px;"
                   "    color: #ffffff;"
                   "    font-size: 16px;"

                   "}"
               );
ui->tabWidget_2->setStyleSheet(tabWidget_style);
  ui->supp_veh->setStyleSheet(button1_style);
ui->ajouter_vehicule->setStyleSheet(button1_style);
ui->modifier_vehicule->setStyleSheet(button1_style);
 ui->stat_veh->setStyleSheet(button1_style);
  ui-> pb_Maintenance->setStyleSheet(button1_style);


  ui->groupBox_15->setStyleSheet(group_box_style);
  ui->groupBox_16->setStyleSheet(group_box_style);


  QString logoStyle = R"(
                       QLabel {
                           background:   #708090);
                           border: 1px solid #A9A9A9;
                           border-radius: 5px;
                           margin: 10px;
                       }
                   )";
  QString buttonStyle = R"(
      QPushButton {
          background-color: rgba(70, 130, 180, 150); /* Transparent medium blue color */
          color: white;
          border: 1px solid rgba(70, 130, 180, 150); /* Transparent border */
          border-radius: 5px;
          padding: 10px 20px;
          font-size: 16px;
      }
      QPushButton:hover {
          background-color: rgba(255, 0, 0, 150); /* Transparent red color on hover */
          border: 1px solid rgba(255, 0, 0, 150); /* Transparent border on hover */
      }
  )";
ui->go_back->setStyleSheet(   "QPushButton {"
                              "   background-color: transparent;"
                              "}"
                              "QPushButton:pressed {"
                              "   background-color: rgba(0, 0, 0, 30); /* Semi-transparent color on press */"
                              "}");
  QString menu = R"(
      QLabel {
          font-size: 32px;          /* Larger font size for the title */
          font-weight: bold;        /* Bold font */
          color: #2c3e50;           /* Text color (dark gray) */
          margin: 20px 0;           /* Margin on top and bottom */
          text-align: center;       /* Center-align text */
      }
  )";

  ui->menu_tit->setStyleSheet(menu);

  ui->logo_label->setStyleSheet(logoStyle);
  ui->menu1->setStyleSheet(buttonStyle);
 ui->menu2->setStyleSheet(buttonStyle);
  ui->menu3->setStyleSheet(buttonStyle);
   ui->menu4->setStyleSheet(buttonStyle);
    ui->menu5->setStyleSheet(buttonStyle);
    ui->label_75->setStyleSheet(titleStyleSheet);
     ui->label_74->setStyleSheet(titleStyleSheet);
      ui->lineEdit_17->setStyleSheet(lineEdit_style);
       ui->lineEdit_18->setStyleSheet(lineEdit_style);
        ui->lineEdit_19->setStyleSheet(lineEdit_style);
         ui->lineEdit_20->setStyleSheet(lineEdit_style);
          ui->lineEdit_21->setStyleSheet(lineEdit_style);
           ui->lineEdit_22->setStyleSheet(lineEdit_style);
            ui->lineEdit_23->setStyleSheet(lineEdit_style);
             ui->lineEdit_24->setStyleSheet(lineEdit_style);
               ui->lineEdit_id_3->setStyleSheet(lineEdit_style);
               ui->lineEdit_produit_3->setStyleSheet(lineEdit_style);
               ui->lineEdit_etat_3->setStyleSheet(lineEdit_style);
                  ui->lineEdit_idrecherche_3->setStyleSheet(lineEdit_style);
                     ui->lineEdit_idrecherche_8->setStyleSheet(lineEdit_style);
                       ui->lineEdit_idsup_3->setStyleSheet(lineEdit_style);
                           ui->tabWidget_3->setStyleSheet(tabWidget_style);
                                     ui->le_IDC->setStyleSheet(lineEdit_style);
                                       ui->le_nomc->setStyleSheet(lineEdit_style);
                                         ui->le_prenomc->setStyleSheet(lineEdit_style);
                                         ui->le_adressec->setStyleSheet(lineEdit_style);
                                          ui->le_nb_commande->setStyleSheet(lineEdit_style);
ui->le_emailc->setStyleSheet(lineEdit_style);
ui->le_numeroc->setStyleSheet(lineEdit_style);

ui->comboBox_tri_zii->setStyleSheet(combobox_style);
ui->pb_pdf->setStyleSheet(button1_style);
ui->pb_Update->setStyleSheet(button1_style);
ui->ajout_clients->setStyleSheet(button1_style);
        ui->pb_supprimer->setStyleSheet(button1_style);
         ui->pb_FeedBack->setStyleSheet(button1_style);
          ui->pb_fidelite->setStyleSheet(button1_style);
 ui->x_chercher->setStyleSheet(lineEdit_style);
ui->le_IDsupp->setStyleSheet(lineEdit_style);
ui->id_fidele->setStyleSheet(lineEdit_style);
ui->le_prob->setStyleSheet(lineEdit_style);
ui->id_FeedBack->setStyleSheet(lineEdit_style);
ui->le_pack->setStyleSheet(lineEdit_style);
ui->le_comu->setStyleSheet(lineEdit_style);
ui->le_time->setStyleSheet(lineEdit_style);
ui->le_rating->setStyleSheet(lineEdit_style);
ui->tab_Clients->setStyleSheet(tab_style);
ui->comboBox_4->setStyleSheet(combobox_style);
ui->group_box_vehicule_2->setStyleSheet(group_box_style);
ui->groupBox_15->setStyleSheet(group_box_style);
ui->groupBox_16->setStyleSheet(group_box_style);
ui->groupBox_17->setStyleSheet(group_box_style);
ui->groupBox_18->setStyleSheet(group_box_style);
ui->creation_3->setStyleSheet(group_box_style);
ui->groupBox_25->setStyleSheet(group_box_style);
ui->groupBox_26->setStyleSheet(group_box_style);
ui->groupBox_27->setStyleSheet(group_box_style);
ui->groupBox_28->setStyleSheet(group_box_style);
ui->tableView_livreur->setStyleSheet(tab_style);
ui->le_id_livreur->setStyleSheet(tab_style);
ui->le_nom_livreur->setStyleSheet(tab_style);
        ui->le_prenom_livreur->setStyleSheet(tab_style);
        ui->pb_ajouter_livreur->setStyleSheet(button1_style);
        ui->tab_FeedBack->setStyleSheet(tab_style);
        ui->groupBox_4->setStyleSheet(group_box_style);
        ui->pushButton_4_livreur->setStyleSheet(button1_style);
        ui->pushButton_14_livreur->setStyleSheet(button1_style);
                   ui->btnRech_livreur->setStyleSheet(button1_style);
                    ui->valider_livreur->setStyleSheet(button1_style);
                      ui->reset_livreur->setStyleSheet(button1_style);
                               ui->btnTriAsc_livreur->setStyleSheet(button1_style);
                                     ui->pb_modifier_livreur->setStyleSheet(button1_style);
                                   ui->ConfirmationButton_3_livreur->setStyleSheet(button1_style);
                                            ui->pb_supp_livreur->setStyleSheet(button1_style);
                                    ui-> comboBox_supp_livreur->setStyleSheet(combobox_style);
                                    ui->pdf_livreur->setStyleSheet(button1_style);

                                   ui-> comboBox_modi_livreur->setStyleSheet(combobox_style);
                                    ui-> lineEdit_15_livreur->setStyleSheet(lineEdit_style);
                                     ui-> lineEdit_16_livreur->setStyleSheet(lineEdit_style);
                                     ui-> le_id_livreur->setStyleSheet(lineEdit_style);
                                       ui-> le_prenom_livreur->setStyleSheet(lineEdit_style);
                                        ui-> le_prenom2_livreur->setStyleSheet(lineEdit_style);
                                             ui-> le_nom_livreur->setStyleSheet(lineEdit_style);
                                              ui-> le_nom2_livreur->setStyleSheet(lineEdit_style);
 ui-> le_num_livreur->setStyleSheet(lineEdit_style);
 ui-> le_num2_livreur->setStyleSheet(lineEdit_style);
  ui-> tab_Clients_2->setStyleSheet(tab_style);
   ui-> calculscore_livreur->setStyleSheet(button1_style);
     ui-> pushButton_13_livreur->setStyleSheet(button1_style);
       ui-> rechid_livreur->setStyleSheet(lineEdit_style);
         ui-> rechnom_livreur->setStyleSheet(lineEdit_style);
           ui-> rechnumero_livreur->setStyleSheet(lineEdit_style);
             ui-> lineEditId_livreur->setStyleSheet(lineEdit_style);
               ui-> lineEditNbrLivs_livreur->setStyleSheet(lineEdit_style);
                 ui-> lineEditTaux_livreur->setStyleSheet(lineEdit_style);

}

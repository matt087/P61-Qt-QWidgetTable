#include "personadialog.h"
#include "ui_personadialog.h"

PersonaDialog::PersonaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonaDialog)
{
    ui->setupUi(this);
}

PersonaDialog::~PersonaDialog()
{
    delete ui;
}

void PersonaDialog::on_buttonBox_accepted()
{
    QString nombre = ui->inNombre->text();
    QString apellido = ui->inApellido->text();
    QString telefono = ui->inTelefono->text();
    QString email = ui->inEmail->text();

    bool valid=false;

    QMessageBox adv;
    adv.setIcon(QMessageBox::Warning);
    adv.setWindowTitle("Ingreso de Datos");

    if(nombre.isEmpty()&&apellido.isEmpty()&&telefono.isEmpty()&&email.isEmpty())
    {
        adv.setText("Todos los campos de texto están vacíos"); adv.exec();
        return;
    }

    if(nombre.isEmpty() || apellido.isEmpty() || telefono.isEmpty() || email.isEmpty())
    {
        adv.setText("Hay campos de texto vacíos"); adv.exec();
        return;
    }

    for(int i=0; i<nombre.length(); i++)
    {
        if(nombre[i].isDigit())
        {
            adv.setText("El campo de texto \"Nombre\" solo admite letras"); adv.exec();
            return;
        }
    }


    for(int i=0; i<apellido.length(); i++)
    {
        if(apellido[i].isDigit())
        {
            adv.setText("El campo de texto \"Apellido\" solo admite letras"); adv.exec();
            return;
        }
    }


    for(int i=0; i<telefono.length(); i++)
    {
        if(!telefono[i].isDigit())
        {
            adv.setText("El campo de texto \"Teléfono\" solo admite números"); adv.exec();
            return;
        }
    }

    for(int i=0; i<email.length(); i++)
    {
        if(email[i]=="@")
        {
            for(int j=i; j<email.length(); j++)
            {
                if(email[j] == ".")
                    valid = true;
            }
        }
    }

    if(!valid)
    {
        adv.setText("El email ingresado es incorrecto"); adv.exec();
        return;
    }

    this->m_persona = new Persona(nombre, apellido, telefono, email);
    accept();
}

void PersonaDialog::on_buttonBox_rejected()
{
    reject();
}

Persona *PersonaDialog::persona() const
{
    return m_persona;
}

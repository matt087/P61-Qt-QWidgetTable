#include "editpersona.h"
#include "ui_editpersona.h"

editpersona::editpersona(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editpersona)
{
    ui->setupUi(this);
}

editpersona::~editpersona()
{
    delete ui;
}

Persona *editpersona::persona() const
{
    return m_persona;
}

void editpersona::on_buttonBox_accepted()
{
    QString nombre = ui->nombre->text();
    QString apellido = ui->apellido->text();
    QString telefono = ui->telefono->text();
    QString email = ui->email->text();
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


void editpersona::on_buttonBox_rejected()
{
    reject();
}


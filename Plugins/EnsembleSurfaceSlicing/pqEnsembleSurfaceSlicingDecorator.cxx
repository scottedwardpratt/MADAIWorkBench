/*=========================================================================

   Program: ParaView
   Module:    pqEnsembleSurfaceSlicingDecorator.cxx

   Copyright (c) 2005,2006 Sandia Corporation, Kitware Inc.
   All rights reserved.

   ParaView is a free software; you can redistribute it and/or modify it
   under the terms of the ParaView license version 1.2. 

   See License_v1.2.txt for the full ParaView license.
   A copy of this license can be obtained by contacting
   Kitware Inc.
   28 Corporate Drive
   Clifton Park, NY 12065
   USA

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

========================================================================*/
#include "pqEnsembleSurfaceSlicingDecorator.h"
#include "ui_pqEnsembleSurfaceSlicingDecorator.h"
// Server Manager Includes.

// Qt Includes.
#include <QVBoxLayout>

// ParaView Includes.
#include "pqDisplayPanel.h"
#include "pqDisplayProxyEditor.h"
#include "pqPipelineRepresentation.h"
#include "vtkSMProxy.h"

// VTK includes
#include <vtkEventQtSlotConnect.h>
#include <vtkSmartPointer.h>


class pqEnsembleSurfaceSlicingDecorator::pqInternals :
  public Ui::pqEnsembleSurfaceSlicingDecorator
{
public:
  vtkSMProxy*                            RepresentationProxy;
  vtkSmartPointer<vtkEventQtSlotConnect> VTKConnect;
  pqPipelineRepresentation*              PipelineRepresentation;

  pqInternals(QWidget* parent)
  {
    this->RepresentationProxy = NULL;
    this->VTKConnect = vtkSmartPointer<vtkEventQtSlotConnect>::New();
  }
};

//-----------------------------------------------------------------------------
pqEnsembleSurfaceSlicingDecorator::pqEnsembleSurfaceSlicingDecorator(pqDisplayPanel* displayPanel)
  : Superclass(displayPanel)
{
  this->setTitle( "Ensemble Surface Slicing" );

  pqDisplayProxyEditor* panel =
      qobject_cast<pqDisplayProxyEditor*> (displayPanel);
  pqRepresentation* representation = panel->getRepresentation();
  vtkSMProxy* representationProxy = (representation) ? representation->getProxy() : NULL;

  this->Internals = new pqInternals(this);
  QVBoxLayout* vlayout = qobject_cast<QVBoxLayout*>(panel->layout());
  if (vlayout)
    {
    vlayout->insertWidget(2, this);
    }
  else
    {
    panel->layout()->addWidget(this);
    }
  this->Internals->setupUi(this);
  this->Internals->RepresentationProxy = representationProxy;

  this->setupGUIConnections();
}

//-----------------------------------------------------------------------------
pqEnsembleSurfaceSlicingDecorator::~pqEnsembleSurfaceSlicingDecorator()
{
  delete this->Internals;
}

//-----------------------------------------------------------------------------
void pqEnsembleSurfaceSlicingDecorator::setupGUIConnections()
{
  this->connect(this->Internals->sliceWidthEdit, SIGNAL(editingFinished()),
                SLOT(onSliceWidthChanged()));

}

//-----------------------------------------------------------------------------
void pqEnsembleSurfaceSlicingDecorator::onSliceWidthChanged()
{
  std::cout << this->Internals->sliceWidthEdit->text().toStdString() << std::endl;
}
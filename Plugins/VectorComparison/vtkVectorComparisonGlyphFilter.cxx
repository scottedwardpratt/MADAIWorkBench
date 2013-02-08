#include "vtkVectorComparisonGlyphFilter.h"

#include "vtkAlgorithm.h"
#include "vtkInformation.h"

vtkStandardNewMacro(vtkVectorComparisonGlyphFilter);


//----------------------------------------------------------------------------
vtkVectorComparisonGlyphFilter::vtkVectorComparisonGlyphFilter()
{
  this->SetNumberOfInputPorts(2);
  this->SetNumberOfOutputPorts(1);
}

//----------------------------------------------------------------------------
vtkVectorComparisonGlyphFilter::~vtkVectorComparisonGlyphFilter()
{

}

//----------------------------------------------------------------------------
void vtkVectorComparisonGlyphFilter::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
}

//----------------------------------------------------------------------------
int vtkVectorComparisonGlyphFilter::RequestData(
  vtkInformation *vtkNotUsed(request),
  vtkInformationVector **inputVector,
  vtkInformationVector *outputVector)
{
  return 1;
}

//----------------------------------------------------------------------------
int vtkVectorComparisonGlyphFilter::RequestUpdateExtent(
  vtkInformation *vtkNotUsed(request),
  vtkInformationVector **inputVector,
  vtkInformationVector *outputVector)
{
  return 1;
}

//----------------------------------------------------------------------------
int vtkVectorComparisonGlyphFilter::FillInputPortInformation(int port, vtkInformation *info)
{
#if 0
  if (port == 1)
    {
    info->Set(vtkAlgorithm::INPUT_IS_OPTIONAL(), 0);
    }
#endif

  if (port == 0 || port == 1)
    {
    info->Set(vtkAlgorithm::INPUT_REQUIRED_DATA_TYPE(), "vtkDataSet");
    return 1;
    }
    
  return 0;
}

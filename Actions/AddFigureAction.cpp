#include "AddFigureAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddFigureAction::AddFigureAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddFigureAction::ReadActionParameters()
{}

void AddFigureAction::Execute(bool ReadActionParams)
{
	UI.InterfaceMode = MODE_SHAPES; // To draw shapes toolbar
}



#include "DeleteFigureAction.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DeleteFigureAction::DeleteFigureAction(ApplicationManager* pApp) : Action(pApp)
{
	SelectedFig = NULL;
}

void DeleteFigureAction::ReadActionParameters()
{
}

void DeleteFigureAction::Execute(bool ReadActionParams = true)
{
	Output* pOut = pManager->GetOutput();

	SelectedFig = pManager->GetSelectedFig();

	// Check if there are no Selected Figures
	if (SelectedFig == NULL)
	{
		pOut->PrintMessage("You Must Select A Figure");
		return;
	}

	// Call DeleteFigure function to delete the selected figure
	pManager->DeleteFigure(SelectedFig);

	// Make the figure not highlighted
	SelectedFig->SetSelected(false);

}

void DeleteFigureAction::play()
{
	// Change The Tool Bar
	UI.InterfaceMode = MODE_DRAW;

	Output* pOut = pManager->GetOutput();

	SelectedFig = pManager->GetSelectedFig();

	// Check if there are no Selected Figures
	if (SelectedFig == NULL)
	{
		pOut->PrintMessage("You Must Select A Figure");
		return;
	}

	// Call DeleteFigure function to delete the selected figure
	pManager->DeleteFigure(SelectedFig);

	// Delete the dynamically allocated figure from the memory
	delete SelectedFig;
}

void DeleteFigureAction::DeleteForPlay(CFigure* Fig)
{
	// Call DeleteFigure function to delete the selected figure
	pManager->DeleteFigure(Fig);

	// Delete the dynamically allocated figure from the memory
	delete Fig;
}
void DeleteFigureAction::UndoAct()
{
	if (SelectedFig != NULL)
		pManager->AddFigure(SelectedFig);
	else
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("A Failed Deleting attempt was made");
		return; // In case we added anything else in the future after this condition
	}
}

void DeleteFigureAction::RedoAct()
{
	if (SelectedFig != NULL)
		pManager->DeleteFigure(SelectedFig);
	else
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("A Failed Undo attempt was made");
		return;
	}
}

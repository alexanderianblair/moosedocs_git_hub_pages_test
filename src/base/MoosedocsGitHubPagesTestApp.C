#include "MoosedocsGitHubPagesTestApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
MoosedocsGitHubPagesTestApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

MoosedocsGitHubPagesTestApp::MoosedocsGitHubPagesTestApp(InputParameters parameters) : MooseApp(parameters)
{
  MoosedocsGitHubPagesTestApp::registerAll(_factory, _action_factory, _syntax);
}

MoosedocsGitHubPagesTestApp::~MoosedocsGitHubPagesTestApp() {}

void
MoosedocsGitHubPagesTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<MoosedocsGitHubPagesTestApp>(f, af, s);
  Registry::registerObjectsTo(f, {"MoosedocsGitHubPagesTestApp"});
  Registry::registerActionsTo(af, {"MoosedocsGitHubPagesTestApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
MoosedocsGitHubPagesTestApp::registerApps()
{
  registerApp(MoosedocsGitHubPagesTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
MoosedocsGitHubPagesTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  MoosedocsGitHubPagesTestApp::registerAll(f, af, s);
}
extern "C" void
MoosedocsGitHubPagesTestApp__registerApps()
{
  MoosedocsGitHubPagesTestApp::registerApps();
}

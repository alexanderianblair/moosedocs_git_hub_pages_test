//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "MoosedocsGitHubPagesTestTestApp.h"
#include "MoosedocsGitHubPagesTestApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
MoosedocsGitHubPagesTestTestApp::validParams()
{
  InputParameters params = MoosedocsGitHubPagesTestApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

MoosedocsGitHubPagesTestTestApp::MoosedocsGitHubPagesTestTestApp(InputParameters parameters) : MooseApp(parameters)
{
  MoosedocsGitHubPagesTestTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

MoosedocsGitHubPagesTestTestApp::~MoosedocsGitHubPagesTestTestApp() {}

void
MoosedocsGitHubPagesTestTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  MoosedocsGitHubPagesTestApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"MoosedocsGitHubPagesTestTestApp"});
    Registry::registerActionsTo(af, {"MoosedocsGitHubPagesTestTestApp"});
  }
}

void
MoosedocsGitHubPagesTestTestApp::registerApps()
{
  registerApp(MoosedocsGitHubPagesTestApp);
  registerApp(MoosedocsGitHubPagesTestTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
MoosedocsGitHubPagesTestTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  MoosedocsGitHubPagesTestTestApp::registerAll(f, af, s);
}
extern "C" void
MoosedocsGitHubPagesTestTestApp__registerApps()
{
  MoosedocsGitHubPagesTestTestApp::registerApps();
}

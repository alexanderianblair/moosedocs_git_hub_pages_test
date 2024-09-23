//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "MooseApp.h"

class MoosedocsGitHubPagesTestApp : public MooseApp
{
public:
  static InputParameters validParams();

  MoosedocsGitHubPagesTestApp(InputParameters parameters);
  virtual ~MoosedocsGitHubPagesTestApp();

  static void registerApps();
  static void registerAll(Factory & f, ActionFactory & af, Syntax & s);
};

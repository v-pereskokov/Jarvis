#ifndef COMMANDPYTHON_H
#define COMMANDPYTHON_H

#pragma once

namespace Jarvis {
  namespace Commands {
    class Command {
    public:
      virtual void execute() = 0;
    };
  }
}

#endif // COMMANDPYTHON_H
